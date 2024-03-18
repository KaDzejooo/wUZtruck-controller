# Dobre praktyki według których piszemy kod..

## Ważne !
Przed próbą kompilacji w STM32CubeIDE należy zregenerować projekt klikająć w "Generate code" w TouchGFX Designer, w innym wypadku pojawią się błędy o braku niektórych plików bądż deklaracji, w razie dalszych problemów zalecane jest usunięcie folderu generated z głównego katalogu Touch GFX'a.

## Pull-request / merge into main
- Podczas tworzenie pull-request należy w dostatecznym stopniu opisać co i w jaki sposób zostało zmienione, najlepiej z komplementarnymi zrzutami ekranu
- Całość należy przetestować na faktycznym sprzęcie i upewnić się że działa poprawnie
- W miarę możliwości nie popsuć działania symulatora, którego też należy sprawdzić 



## Nazywanie zmiennych / funkcji
  Reguły nazywania zmiennych:
  - Nazywaj zmienne tylko w języku angielskim. NIGDY nie mieszaj języków w zmiennych:
    > int zmienna; ❌\
    > int variable; ✅\
    > int zmiennaTruck; ❌❌❌ - Jak tak zrobisz wylatujesz z koła 
  - Nazwy zaczynaj od małej litery, a kolejne wyrazy pisz razem z dużej litery:
    > int truckValue; ✅\
    > bool trailerOneConnected; ✅\
    > char* userSurname; ✅\
    > char* usersurname; ❌\
    > int Counter; ❌
  - Staraj się nie używać liczb w nazwach zmiennych. Zamiast tego używaj liczb w formie pisanej:
    > int task1, task2; ❌\
    > char truck1Mode; ❌\
    > int taskOne, taskTwo; ✅
  - NIGDY nie zaczynaj nazwy od liczby:
    > int 1value = 10; ❌

## Odstępy w kodzie
  Zachowuj odpowiednie odstępy w istotnych elementach kodu dla lepszego wyglądu i weryfikacji
  Przykłady:
  - Po napisaniu funkcji / instrukcji if else / loopa zadbaj o niezlewanie się nawiasów z słowami kluczowymi
    > if(expression) {} ✅\
    > if(expression){} ❌
  - Argumenty również oddzielaj spacją
    > function fun1(int arg1, int arg2, char arg3) {} ✅\
    > function fun2(int arg1,int arg2, char arg3){} ❌
  - W wyrażeniu odstępy przy znaku równości jak i dużych wyrażeniach (niewielkie nawiasy możesz zostawić razem, ale przy długich wyrażeniach oddzielaj duże elementy i grupuj w mniejsze)
    > x = a + b; ✅\
    > x=a+b; ❌\
    > x = (a+b) / (a\*b); ✅\
    > x= (a+b)/a\*b); ❌\
    > x = a + ( ( (a+c) * 2 ) / ( (a\*b\*c)^2 + 11) ); ✅\
    > x=a+(((a+c)*2)/((a\*b\*c)^2+11)); ❌
