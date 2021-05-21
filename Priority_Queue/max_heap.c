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

//heap에 삽입하는 함수
void insert_max_heap(HeapType *h, int item)
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

//heap에서 삭제하는 함수
int delete_max_heap(HeapType *h)
{
    //heap이 비어있으면 0을 return 한다
    if (h->heap_size == 0)
    {
        return 0;
    }

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

int main(void)
{
    HeapType *heap;
    heap = create(); //heap 생성
    init(heap);      //heap 초기화

    int loop, x, del;
    scanf("%d", &loop); //연산의 개수를 loop에 입력받는다
    for (int i = 0; i < loop; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        { //x가 0이면 노드를 가장 큰 값을 출력한다
            del = delete_max_heap(heap);
            printf("%d\n", del);
        }
        else
        { //x가 0이 아니면 heap에 x를 삽입한다.
            insert_max_heap(heap, x);
        }
    }

    free(heap);
    return 0;
}