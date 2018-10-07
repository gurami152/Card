/* �������� �����. �������� �������. ��� 2
 ���� �++
 ������ �������
    Init - �������� ������ ����
    Shuffle - ����������� ������ ����
    EnterNumderOfPlayers - ���� ���������� �������
    Trump - ����������� �������� �����
    DistributionFindingWinner - ������� ���� ������� (�������� ������� ����) � ����������� ���������� (����� �������� �������� ������ ����)
    main - ������� ������� ���������
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// ���������� ����������
int decksize =36; // ���������� ���� � ������
int suitsize =4; // ���������� ������ � ������
int Suit[36]; // ������ �������� ��������� �������� ����� ����� � ������
int ShuffleList[36]; // ������ �������� ����������� ������
int Card[36]; // ����� �������� �������� ����� � ������
int array1[36]; //������ ��� �������� �������� ����� � ������
int **Players; // ��������� ������ ��� �������� ������ ���� � ������� �� �����
int CountOfCards=6; // ������������� ���������� ���� �� ����� � ������
unsigned int n=7; // ���������� �������� ���������� �������
string CardList[]={"6","7","8","9","10","�����","����","������","���","6"};// �������� ���� � ������
string SuitList[]={"�����","�����","�����","����"};// �������� ������ � ������

void Shuffle(){ // ����������� ���� � ������

    int k;
    // �������� ������
    for (int g=0; g< 36; g++) {  ShuffleList[g]=0; }
    srand(time(NULL));
    for (int i=0; i < 36; i++){
    //�������� �� ��������������
            while(1)
            {
        k = rand()%36 + 1;
        if (array1[k] == 0 ) { array1[k] = 1; ShuffleList[i] = k; break; }
            }
    }

}

void EnterNumberOfPlayers(){ // ���� ���������� �������
    while(n>6||n==0){
    cout<<"������� ���������� �������"<<endl;
    cin>>n;}
}

int Trump(){ // ����������� �������� �����
    srand(time(NULL));
    int k = rand()%4;
    return k;
}

void DistributionFindingWinner(){ // ������� ���� � ����������� ����������
    EnterNumberOfPlayers();
    // ��������� �� ��������� ����� � ����� ������
    int marker=0;
    // ���������� �� �������� �����
    int TrumpK=1;
    // �������� ������� ��� �������� ������ ���� �������
    Players = new int*[n];
	for (int i = 0; i < n; i++)Players[i] = new int[CountOfCards];
	// ������ ��� �������� ����������� ������� ���� �������
	int *sum = new int[n];
	 // ����������� �������� �����
	 int TrumpSuit=Trump();
	cout<<"\n�������� ����� "<<SuitList[TrumpSuit]<<endl<<endl;
	// ��������� ������� ��������� ��������� ����
	for(int i=0;i<n;i++){
            sum[i]=0;
    }
    // ������� ���� �������
    for(int i=0;i<n;i++){
        cout<<"�����"<<i+1<<endl;
        for(int j=0;j<CountOfCards;j++){
            Players[i][j]=ShuffleList[i+j*n];
            cout<<Players[i][j] <<" "<<SuitList[Suit[Players[i][j]]]<<" "<<CardList[Card[Players[i][j]]]<< endl; // ����� �����
            if(TrumpSuit==Suit[Players[i][j]]){// ����������� �������� ����� ��� ���
                    TrumpK=2;
            }
            else{
                    TrumpK=1;
            }
            // ������ ��������� ������ ����
            sum[i]=sum[i]+(Card[Players[i][j]]+6)*TrumpK;
        }cout<<"����� ������ �"<<i+1<<":"<<sum[i]<<endl<<endl;
    }
    // ����������� �������� ������� �����
    // ����������� ���������
    int Max=sum[0];
    // ����� ������ � ������������ ����������
    int Winner=1;
    for(int i=1;i<n;i++){
           if(sum[i]>Max){
                Max=sum[i];
                Winner=i+1;
           }
    }
    cout<<"�������� ������� ����� ���� � ������ ��� ������� "<<Winner<<endl;
}

void Init(){ // �������� ������
        int id=-1;
        for(int i=0; i<=decksize/suitsize;i++){
            for(int j=0;j<suitsize;j++){
                id++;
                Suit[id]=j;
                Card[id]=i;
            }
        }
}



int main()
{
    // ����������� �������� �����
    setlocale(LC_CTYPE, "");
    cout<<"�������� �����. �������� �������. 2 ���."<<endl;
    // �������� ������
    Init();
    // ����������� ������
    Shuffle();
    // ������� ���� � ����������� ����������
    DistributionFindingWinner();
     // �������� ����� ������� �� ���������
    system("pause");
    return 0;
}
