Submit your C program source file and execution screen capture file.

You must check your program at https://repl.it/languages/c or https://www.onlinegdb.com/online_c_compiler.

 

이젠 따로 적지 않아도, 소스코드 온라인 컴파일러에서 돌려보고 여기서 실행화면 캡쳐해서 제출하는 기본은 알죠?

모든 과제는 온라인 컴파일러에서 실행되는 소스, 실행화면 꼭 제출하세요. 

 

그리고, 꼭 예시만 테스트하지 말고 다양한 입력으로 테스트를 해보고 제출하는 것도 기본입니다. 

 

=================================================================

 

Get the family names, ages, Math scores, English scores, History scores of the students in a class
by a file.
Save them using "Struct" and "dynamic memory allocation".
And, print out their sorted results based on the field a user chooses.
한 클래스의 학생들의 정보(성, 나이)와 성적(수학, 영어, 역사)을 파일로 입력받아
이를 구조체와 동적메모리할당을 이용해 저장하고,
이를 사용자의 요구에 따라 정렬하여 출력하는 프로그램을 작성하시오.

The requirements are as follows.
- Because you can not know the number of students in a class in advance,
you should use dynamic memory allocation of struct.
- You should check whether the ages are the integers greater than 0
and the scores are in [0, 100] during input process.
- You should sort the family names(alphabet order), the ages and the scores in ascending order.
The data with the same rank may be not ordered.
If a user choose a field to sort by, the sorted results of the students should be printed out by the field.
- You will get 10 points if you implement selection menu, 1) Insert and 3) Quit. You will get 20 points if you implement 2) Sort additionally.

세부사항은 다음과 같음.
- 학생들은 몇 명인지 모르니 입력이 들어오는 순서대로 구조체의 동적할당으로 저장할 것.
- 나이는 양의 정수, 성적은 [0, 100]의 범위를 가저야 하니, 입력 중에 체크할 것.
- 정렬의 기준은 모두 오름차순이나 성, 나이, 과목 성적을 선택할 수 있도록 하여,
선택된 기준으로 오름차순 정렬결과를 보여주어야 함.
성은 알파벳 순, 나이와 성적은 정수 비교. 동일 순위내의 정렬은 순서 상관없음.
- 점수는 선택메뉴와 입력, 프로그램 종료가 구현되면 10점, 정렬까지 구현되면 20점

<Test file>
[input1.txt]
kim -2 11 10 100
lee 9 18 90 55 

[input2.txt]
gu 10 12 50 99
kim 24 20 50 34
lee 23 33 40 33
sung 30 40 22 12

<Execution Example>
<실행 예>
============================
1) Insert
2) Sort
3) Quit
Select a menu : 2

Result : There is no data to be sorted. Program terminates.
============================

============================
1) Insert
2) Sort
3) Quit
Select a menu : 1

File name : input1.txt   
Result : The age cannot be a negative number. Program terminates.
============================


============================
1) Insert
2) Sort
3) Quit
Select a menu : 1

File name : input2.txt       
Result :
No Name Age Math English History
1 gu 10 12 50 99
2 kim 24 20 50 34
3 lee 23 33 40 33
4 sung 30 40 22 12


1) Insert
2) Sort
3) Quit
Select a menu : 2

1) Name
2) Age
3) Math
4) English
5) History
Choose the field to sort by : 4

No English Name Age Math History
1 22 sung 30 40 12
2 40 lee 23 33 33
3 50 gu 10 12 99
4 50 kim 24 20 34


1) Insert
2) Sort
3) Quit
Select a menu : 2

1) Name
2) Age
3) Math
4) English
5) History
Choose the field to sort by : 1

No Name Age Math English History
1 gu 10 12 50 99
2 kim 24 20 50 34
3 lee 23 33 40 33
4 sung 30 40 22 12


1) Insert
2) Sort
3) Quit
Select a menu : 3
 
==========================