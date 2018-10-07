/* Дребезов Денис. Тестовое задание. Тур 2
 Язык С++
 Список функций
    Init - Создание колоды карт
    Shuffle - Перетасовка колоды карт
    EnterNumderOfPlayers - Ввод количества игроков
    Trump - Определение козырной масти
    DistributionFindingWinner - Раздача карт игрокам (Создание наборов карт) и определение победителя (Поиск наиболее сильного набора карт)
    main - главная функция программы
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// глобальные переменные
int decksize =36; // количество карт в колоде
int suitsize =4; // количество мастей в колоде
int Suit[36]; // массив храняший положение значение масти карты в колоде
int ShuffleList[36]; // массив храняший перемешаную колоду
int Card[36]; // масив хранящий значение карты в колоде
int array1[36]; //массив для проверки единства карты в колоде
int **Players; // двумерный массив для хранения набора карт у игроков на руках
int CountOfCards=6; // масксимальное количество карт на руках у игрока
unsigned int n=7; // переменная хранящая количество игроков
string CardList[]={"6","7","8","9","10","Валет","Дама","Король","Туз","6"};// названия карт в колоде
string SuitList[]={"Чирва","Бубна","Трефа","Пика"};// названия мастей в колоде

void Shuffle(){ // перетасовка карт в колоде

    int k;
    // обнуляем массив
    for (int g=0; g< 36; g++) {  ShuffleList[g]=0; }
    srand(time(NULL));
    for (int i=0; i < 36; i++){
    //проверка на единственность
            while(1)
            {
        k = rand()%36 + 1;
        if (array1[k] == 0 ) { array1[k] = 1; ShuffleList[i] = k; break; }
            }
    }

}

void EnterNumberOfPlayers(){ // ввод количества игроков
    while(n>6||n==0){
    cout<<"Введите количество игроков"<<endl;
    cin>>n;}
}

int Trump(){ // определение козырной масти
    srand(time(NULL));
    int k = rand()%4;
    return k;
}

void DistributionFindingWinner(){ // раздача карт и определение победителя
    EnterNumberOfPlayers();
    // указатель на следующую карту в руках игрока
    int marker=0;
    // коэфициент на козырную масть
    int TrumpK=1;
    // создание массива для хранения набора карт игроков
    Players = new int*[n];
	for (int i = 0; i < n; i++)Players[i] = new int[CountOfCards];
	// массив для хранения ммощьностей наборов карт игроков
	int *sum = new int[n];
	 // определение козырной масти
	 int TrumpSuit=Trump();
	cout<<"\nКозырная масть "<<SuitList[TrumpSuit]<<endl<<endl;
	// обнуление массива хранящего мощьность карт
	for(int i=0;i<n;i++){
            sum[i]=0;
    }
    // раздача карт игрокам
    for(int i=0;i<n;i++){
        cout<<"Игрок"<<i+1<<endl;
        for(int j=0;j<CountOfCards;j++){
            Players[i][j]=ShuffleList[i+j*n];
            cout<<Players[i][j] <<" "<<SuitList[Suit[Players[i][j]]]<<" "<<CardList[Card[Players[i][j]]]<< endl; // вывод карты
            if(TrumpSuit==Suit[Players[i][j]]){// определение козырная карта или нет
                    TrumpK=2;
            }
            else{
                    TrumpK=1;
            }
            // расчет мощьности набора карт
            sum[i]=sum[i]+(Card[Players[i][j]]+6)*TrumpK;
        }cout<<"Сумма игрока №"<<i+1<<":"<<sum[i]<<endl<<endl;
    }
    // определение наиболее мощьной карты
    // максиальная мощьность
    int Max=sum[0];
    // номер игрока с максимальной мощьностью
    int Winner=1;
    for(int i=1;i<n;i++){
           if(sum[i]>Max){
                Max=sum[i];
                Winner=i+1;
           }
    }
    cout<<"Наиболее сильный набор карт у игрока под номером "<<Winner<<endl;
}

void Init(){ // создание колоды
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
    // подключение русского языка
    setlocale(LC_CTYPE, "");
    cout<<"Дребезов Денис. Тестовое задание. 2 тур."<<endl;
    // создание колоды
    Init();
    // перетосовка колоды
    Shuffle();
    // раздача карт и определение победителя
    DistributionFindingWinner();
     // Задержка перед выходом из программы
    system("pause");
    return 0;
}
