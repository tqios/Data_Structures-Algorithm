#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5050

typedef int element;
typedef struct {
    int num;
    int imp;
}data;

typedef struct {
    int front;
    int rear;
    data doc[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q) {
    q->rear = -1;
    q->front = -1;
}

int is_full(QueueType* q) {
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType* q) {
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void enqueue(QueueType* q, element item, element imp) {
    if (is_full(q) == 1) {
        return;
    }
    data d;
    d.num = item;
    d.imp = imp;
    q->doc[++(q->rear)] = d;
}

data dequeue(QueueType* q) {
    if (is_empty(q) == 1) {
        exit;
    }
    return q->doc[++(q->front)];
}

int main(void) {
    QueueType q;

    int loop, docn, num, impt;
    int comp = 101;
    scanf("%d", &loop);

    //loop만큼 반복
    for (int i = 0; i < loop; i++) {
        init_queue(&q);//큐초기화
        int count = 0;//카운트 초기화

        //큐에 정보를 넣어주는 작업
        scanf("%d %d", &docn, &num); //첫번째줄 문서의 개수와 찾을 문서번호를 입력받음
        for (int i = 0; i < docn; i++) { //문서의 개수만큼 중요도를 입력받음
            scanf("%d", &impt);
            enqueue(&q, i, impt); //Queue에 문서의번호와 중요도를 넣음
        }
        while (comp != num) {
            data d = dequeue(&q);//하나를 디큐함
            //가장 큰 중요도 찾기
            int max = 1;//max초기화
            for (int a = q.front; a <= q.rear; a++) {
                if (q.doc[a].imp > max) {
                    max = q.doc[a].imp;
                }
            }
            //중요도가 가장큰값이 아닐경우
            if (d.imp != max) {
                enqueue(&q, d.num, d.imp);//다시 맨뒤로 넣음
            }
            //가장 큰값인 경우
            else {
                comp = d.num;//비교값을 바꿔줌
                count += 1;//카운트 늘임
            }
        }
        printf("%d\n", count);
    }
    return 0;
}