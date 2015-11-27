#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

const int G_delimeter = 96; // [`] ASCII value

unsigned int G_x_position = 1;
unsigned int G_y_position = 1;

//계정의 정보를 저장하는 구조체
typedef struct
{
	char id[12];						//계정 id
	char password[12];					//계정 비밀번호
	int is_account_active;				//계정활성화여부
	int account_authority;				//계정권한 (0:환자, 1:의료인, 2:관리자)
	int serial_number;                  //일련번호
}UserAccount;

//환자의 개인정보를 저장하는 구조체
typedef struct
{
	char patient_name[12];				//환자이름
	char patient_address[80];			//주소
	char patient_phone_number[13];		//전화번호
	char patient_phone_number_2[13];	//전화번호2
	char patient_note[50];				//유의사항
	int patient_number;					//환자번호
	int patient_sex;					//성별
	int patient_rrn_front;				//주민등록번호(resident registration numbe) 앞자리
	int patient_rrn_back;				//주민등록번호(resident registration numbe) 뒷자리
	int patient_birthday;				//생일
	int is_lunar_calendar;				//음력인가 양력인가를 확인
	int patient_first_visit;			//최초방문일
	int patient_last_visit;				//최근방문일
	int patient_schedule_date;			//예약일자
	int patient_visit_num;				//방문횟수					
	int patient_tooth[40];				//치아상태
}PatientInfo;

//환자의 진료정보를 저장하는 구조체
typedef struct
{
	int checkup_date;		//검진일자
	int tooth_num;			//치아번호
	int symptom;			//증상
	int treatment;			//치료
	char content[600];		//내용
}PatientNO;

//예약을 위한 구조체
typedef struct
{
	int date;						//날자
	int is_business_day;			//진료일 여부를 확인
	char is_business_hour[48];		//30분 단위로 하루(24시간)을 나눔
}Schedule;

//메세지를 위한 구조체
typedef struct
{
	int sender_id;			//발신자 id
	int receiver_id;		//수신자 id
	int is_cofirm;			//메세지가 확인되었는가를 체크
	char content[600];		//내용
}Message;

//설문조사를 위한 구조체
typedef struct
{
	int checkup_date;		//검진일자
	int tooth_num;			//치아번호
	int symptom;			//증상
	int treatment;			//치료
	char content[600];		//내용
}Servey;

int accountAccess(char* id, char* pw);

int main()
{
	//moveCursor();
	return 0;
}






