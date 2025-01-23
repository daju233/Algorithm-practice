class Solution {
    std::unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* newHead = new Node(head->val);
        map[head] = newHead;
        newHead->next = copyRandomList(head->next);
        newHead->random = map[head->random];
        return newHead;
    }
};//哈希表法

struct Node* copyRandomList(struct Node* head) {
    if(NULL==head)
        return NULL;
	int len=0;
    struct Node*cmp=head;
    //计算链表长度
    while(cmp){
        len++;
        cmp=cmp->next;
    }
    //创建链表指针数组
    struct Node* arr[len];
    //复制原链表各节点的val到数组中各个节点，顺便给原链表从0~len-1编号
    cmp=head;
    for(int i=0;cmp!=NULL;cmp=cmp->next,i++){
        arr[i]=(struct Node*)malloc(sizeof(struct Node));
        arr[i]->val=cmp->val;
        cmp->val=i;
    }
    //处理随机指针
    cmp=head;
    for(int i=0;cmp!=NULL;cmp=cmp->next,i++){
        if(NULL==cmp->random){
            arr[i]->random=NULL;
        }else{
            arr[i]->random=arr[cmp->random->val];
        }
    }
    //将数组各节点链接成链表
    for(int i=0;i<len-1;i++){
        arr[i]->next=arr[i+1];
    }
    arr[len-1]->next=NULL;
    return arr[0];
}//数组转链表，硬for
