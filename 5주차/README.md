## Lab04-1 Insertion Sort

# insertionSort 프로그램은 사용자로부터 n을 입력받습니다. 
# 이후,  0~n까지 랜덤하게 생성된 n개의 수를 Insertion Sort로 정렬합니다.
# 이때, sort의 실행 시간과 sort가 완벽하게 되었는지를 점검하는 문구를 출력합니다.

# 실행 command

g++ -o insertionSort insertionSort.cpp
./insertionSort

## Lab04-2 Shell Sort

# shellSort 프로그램은 사용자로부터 배열의 크기 n과(1) gap sequence의 key(2)를 입력받습니다.  
# 이후, 0~n까지 랜덤하게 생성된 n개의 수를 gap을 통해 Shell Sort로 정렬합니다. 
# key=2 -> shellSort1, key=3-> shellSort2, key=11 -> shellSort3와 같이 gap이 설정됩니다. 
# 이때, gap sequence와 sort의 실행 시간, sort가 완벽하게 되었는지를 점검하는 문구를 출력합니다.

# 실행 command 

g++ -o shellSort shellSort.cpp
./shellSort

