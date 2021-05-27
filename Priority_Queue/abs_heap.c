//완성 X
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct
{
    int heap[MAX_SIZE];
    int heap_size;
} HeapType;

//heap 생성 함수
HeapType *create()
{
    return (HeapType *)malloc(sizeof(HeapType));
}

//heap 초기화 함수
void init(HeapType *h)
{
    h->heap_size = 0;
}

//heap에 삽입하는 함수 - 음수
void insert_neg_heap(HeapType *h, int item)
{
    int i;
    i = ++(h->heap_size);

    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item > h->heap[i / 2]))
    {                                //h->heap[i/2](부모노드)보다 item 이 크고 i가 1이 아닐 동안 반복
        h->heap[i] = h->heap[i / 2]; //heap[i]에 부모노드의 값을 넣는다
        i /= 2;                      //i를 부모노드의 인덱스로 바꾼다.
        //트리를 거슬러 올라가는 과정
    }
    h->heap[i] = item; //새로운 노드를 삽입
}

//heap에서 삭제하는 함수 - 음수
int delete_neg_heap(HeapType *h)
{
    int parent, child;
    int item, temp;

    //루트 노드를 item에 넣는다
    item = h->heap[1];
    //마지막 노드를 temp에 넣는다
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    { //현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다
        if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])
            //같은 레벨의 노드 중 큰 노드와 바꿔야 하므로 큰 노드의 인덱스를 child로 지정한다
            child++;
        if (temp >= h->heap[child])
            break;
        //한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

//heap에 삽입하는 함수 - 양수
void insert_pos_heap(HeapType *h, int item)
{
    int i;
    i = ++(h->heap_size);

    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item < h->heap[i / 2]))
    {                                //h->heap[i/2](부모노드)보다 item 이 작고 i가 1이 아닐 동안 반복
        h->heap[i] = h->heap[i / 2]; //heap[i]에 부모노드의 값을 넣는다
        i /= 2;                      //i를 부모노드의 인덱스로 바꾼다.
        //트리를 거슬러 올라가는 과정
    }
    h->heap[i] = item; //새로운 노드를 삽입
}

//heap에서 삭제하는 함수 - 양수
int delete_pos_heap(HeapType *h)
{
    int parent, child;
    int item, temp;

    //루트 노드를 item에 넣는다
    item = h->heap[1];
    //마지막 노드를 temp에 넣는다
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    { //현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다
        if ((child < h->heap_size) && (h->heap[child]) > h->heap[child + 1])
            //같은 레벨의 노드 중 작은 노드와 바꿔야 하므로 작은 노드의 인덱스를 child로 지정한다
            child++;
        if (temp <= h->heap[child])
            break;
        //한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int delete_heap(HeapType *h_pos, HeapType *h_neg)
{
    //heap이 둘 다 비어있으면 0을 return 한다
    if (h_pos->heap_size == 0 && h_neg->heap_size == 0)
    {
        return 0;
    }
    int pos = h_pos->heap[1];      //pos에 h_pos의 루트 노드를 넣는다
    int neg = abs(h_neg->heap[1]); //neg에 h_neg의 루트 노드의 절댓값을 넣는다
    if (pos >= neg || h_pos->heap_size == 0)
    { //h_pos가 비어있거나
        //neg가 pos보다 작거나 같으면 neg에서 루트를 삭제하고 return
        return delete_neg_heap(h_neg);
    }
    else
    { //neg가 pos보다 크면 pos에서 루트를 삭제하고 return
        return delete_pos_heap(h_pos);
    }
}

int main(void)
{
    HeapType *heap_pos, *heap_neg;
    heap_pos = create(); //heap_pos 생성 - 양수 저장
    heap_neg = create(); //heap_neg 생성 - 음수 저장
    init(heap_pos);      //heap_pos 초기화
    init(heap_neg);      //heap_neg 초기화

    int loop, x, del;
    scanf("%d", &loop); //연산의 개수를 loop에 입력받는다
    for (int i = 0; i < loop; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        { //x가 0이면 절댓값이 가장 작은 값을 출력한다
            del = delete_heap(heap_pos, heap_neg);
            printf("%d\n", del);
        }
        else if (x > 0)
        { //x가 양수이면 heap_pos에 넣는다
            insert_pos_heap(heap_pos, x);
        }
        else
        { //x가 음수이면 heap_neg에 넣는다
            insert_neg_heap(heap_neg, x);
        }
    }

    free(heap_pos);
    free(heap_neg);
    return 0;
}