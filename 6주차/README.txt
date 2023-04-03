# Lab05-1 Heap Sort (n=10)

- heapSort1 프로그램은 0~9까지 10개의 수를 랜덤 생성하여 벡터에 저장합니다. 
- 이후, 랜덤 벡터를 Max Heap을 이용한 Heap Sort와 Min Heap을 이용한 Heap Sort로 정렬합니다.
- 이때 sort 전과 후의 내용과 sort가 완벽하게 되었는지를 점검하는 문구를 출력합니다.
- bool 타입의 isMaxHeap flag로 프로그램에서 Max Heap 이후 Min Heap을 이용하게 제어합니다.

## 실행 command

g++ -o heapSort1 heapSort1.cpp
./heapSort1

# Lab04-2 Heap Sort (n=2^10, 2^12, 2^14)

- heapSort2 프로그램은 사용자로부터 배열의 크기 n을 입력받습니다. 
- 이후, 0~n까지 랜덤하게 생성된 n개의 수를 Max Heap을 이용한 Heap Sort와 Min Heap을 이용한 Heap Sort로 정렬합니다.
- 이때, sort의 실행 시간과 sort가 완벽하게 되었는지를 점검하는 문구를 출력합니다.
- bool 타입의 isMaxHeap flag로 프로그램에서 Max Heap 이후 Min Heap을 이용하게 제어합니다.

## 실행 command 

g++ -o heapSort2 heapSort2.cpp
./heapSort2

