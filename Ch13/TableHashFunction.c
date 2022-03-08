#include <stdio.h>

typedef struct _empInfo
{
	int empNum;	// employee id
	int age;	// employee age
} EmpInfo;

int GetHashValue(int empNum)
{
	return empNum % 100;
}

int main(void)
{
	EmpInfo empInfoArr[100];

	/**
	 * emp_info = {}
	 * emp_info[20220003] = 42; => empInfoArr[GetHashValue(20220003)] = 42
	 * emp_info[20220012] = 34;
	 * emp_info[20220843] = 20;
	 * 
	 * emp_info = {
	 * 	  20220003: 42,
	 * 	  20220012: 34,
	 * 	  20220843: 20,
	 * }
	 * 
	 * print(emp_info[20220003])	=> print(empInfoArr[GetHashValue(20220003)])
	 * 
	 */
	EmpInfo emp1 = {20220003, 42};
	EmpInfo emp2 = {20220012, 34};
	EmpInfo emp3 = {20220843, 20};

	EmpInfo r1, r2, r3;

	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;

	r1 = empInfoArr[GetHashValue(20220003)];
	r2 = empInfoArr[GetHashValue(20220012)];
	r3 = empInfoArr[GetHashValue(20220843)];

	printf("사번 %d, 나이 %d \n", r1.empNum, r1.age);
	printf("사번 %d, 나이 %d \n", r2.empNum, r2.age);
	printf("사번 %d, 나이 %d \n", r3.empNum, r3.age);

	return 0;
}