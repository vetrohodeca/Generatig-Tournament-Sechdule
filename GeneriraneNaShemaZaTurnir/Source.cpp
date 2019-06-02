#include"Date.cpp"
#include"Turnir.h"
#include"String.h"
int main()
{
	Date d(2, 6, 2019, 9, 00);
	Tournament T(16 ,80,2,"Console",d);
	Tournament* S= T.Create(elimination,T);
	cout<<S->calculateMatches()<<" Matches   "<<S->getNumberOfCourts()<<" Courts   "<<S->getDurationOfMatch()<<"min is one match"<<endl;
	S->MakeSchedule();
	system("pause");
	return 0;
}