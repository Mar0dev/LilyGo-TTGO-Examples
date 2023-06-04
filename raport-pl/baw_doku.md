# Rubber Ducky - projekt

# Spis treści

1. Cel projektu
2. Rubber Ducky
3. Opis urządzenia
4. Przygotowane oprogramowanie  
4.1 downloadMalware.ino  
4.2 processorOverloading.ino  
4.3 restartComputer.ino  
4.4 stealCookies.ino  
4.5 stealPasswd.ino  
4.6 stealWiFiPassword.ino  
4.7 stealWifiConfig.ino  
5. Działania naprawcze/prewencyjne
6. Wnioski

# Cel projektu

Celem tego projektu jest zdobycie wiedzy w zakresie komunikacji z urządzeniami peryferyjnymi. W tym celu wybrano konkretne urządzenie oparte na mikrokontrolerze. Następnie opracowano oprogramowanie symulujące wejścia klawiatury, gdy urządzenie jest podłączone do komputera za pośrednictwem interfejsu USB. Celem tego oprogramowania jest inicjowanie złośliwych działań na urządzeniu.

# Rubber Ducky

Rubber Ducky to narzędzie, które zostało zaprojektowane tak, aby naśladować funkcjonalność standardowej klawiatury USB, ale z dodatkową możliwością automatycznego wykonywania wstępnie skonfigurowanych sekwencji naciśnięć klawiszy, często bez wzbudzania podejrzeń. Swoim wyglądem przypomina urządzenie przenośne zawierającą pamięć nieultoną (pendrive) - nic bardziej mylnego, gdyż urządzenie to, po podłączeniu do komputera automatycznie inicjuje zdefiniowane oprogramowanie.

Aby korzystać z Rubber Ducky, użytkownik wstępnie programuje sekwencję naciśnięć klawiszy przy użyciu specjalistycznego języka skryptowego, który jest specyficzny dla urządzenia Rubber Ducky. Skrypty te definiują sekwencję naciśnięć klawiszy, opóźnień i innych poleceń, które mają zostać wykonane na komputerze docelowym po podłączeniu urządzenia Rubber Ducky przez USB. Gdy urządzenie jest podłączone do komputera docelowego, emuluje standardową klawiaturę USB i wykonuje sekwencję skryptów, skutecznie automatyzując serię działań.

Rubber Ducky może być potężnym narzędziem do różnych celów, w tym automatyzacji powtarzalnych zadań, wykonywania konfiguracji systemu, a nawet wykorzystywania luk w zabezpieczeniach. Warto jednak zauważyć, że jego możliwości mogą być również nadużywane do złośliwych celów, takich jak uzyskiwanie nieautoryzowanego dostępu lub wykonywanie niebezpiecznych działań w systemie komputerowym. Podobnie jak w przypadku każdego innego narzędzia, korzystanie z niego powinno odbywać się w sposób etyczny i zgodny z obowiązującymi przepisami i regulacjami.

# Opis urządzenia

Celem projektu było przygotowanie mikrokontrolera, który będzie w stanie działać analogicznie do urządzenia Rubber Ducky - emulować wciśnięcia klawiszy klawiatury, po podłączeniu do komputera przez USB. By ten cel osiągnąć, zespół projektowy podjął decyzję o wykorzystaniu mikrokontrolera **ATmega32u4**, z modułem **LILYGO TTGO**, który posiada sprzętowy interfejs USB. Dzięki temu nie wymaga dodatkowego mikrokontrolera czy konwertera realizującego tę funkcjonalność, co pozwala to na bardzo łatwe tworzenie aplikacji emulujących wejścia na klawiaturze komputera. Całość  posiada 2,5 kB RAM, 10 cyfrowych wejść/wyjść z czego 4 można wykorzystać jako kanały PWM i 5 jako analogowe wejścia. Moduł ten, jest w pełni zgodny z projektem Arduino, co oznacza, że może być programowany poprzez środowisko Arduino IDE z wykorzystaniem dostępnych bibliotek.

Oto kilka kluczowych powodów, dla których zostały wybrane wyżej wymienione komponenty:
+ **Open-Source**: Arduino to platforma typu open-source, co oznacza, że jej sprzęt i oprogramowanie są ogólnodostępne. Użytkownicy mają dostęp do szerokiej gamy bibliotek, przykładów kodu i pomysłów na projekty, co przyspiesza proces rozwoju.
+ **Dostępność**: Arduino priorytetowo traktuje dostępność, ułatwiając początkującym rozpoczęcie przygody z elektroniką i programowaniem. Zapewnia przyjazne dla użytkownika środowisko programistyczne, uproszczoną składnię (na podstawie języka C++) i rozległą sieć wsparcia społeczności.
+ **Opłacalność**: Płytki zgodne z Arduino są stosunkowo niedrogie w porównaniu do wielu innych platform mikrokontrolerów. Ta dostępność taniego sprzętu sprawia, że Arduino jest atrakcyjnym wyborem, szczególnie dla projektów edukacyjnych z ograniczeniami budżetowymi.
+ **Kompatybilność między platformami**: Arduino IDE (zintegrowane środowisko programistyczne) jest kompatybilne z różnymi systemami operacyjnymi, w tym Windows, macOS i Linux. Ta wieloplatformowa kompatybilność zapewnia, że Arduino może być używane na szerokiej gamie komputerów, zapewniając elastyczność i wygodę co do stworzonego oprogramowania na potrzeby niniejszego projektu.

# Przygotowane oprogramowanie

Charakter użycia przygotowanego mikrokontrolera zakłada stworzenie oprogramowania w oparciu o Arduino IDE, które korzysta z C++ jako języka programowania, a następnie zapisaniu go na urządzeniu. Następnie ono działa jako "złe USB" (odnosi się to do techniki ataku, która wykorzystuje zaprogramowane urządzenie USB do emulowania różnych typów urządzeń). W wyniku działań rozwojowych powstały następujące skrypty:

> Kod źródłowy całego stworzonego oprogramowania można znaleźć w [publicznym repozytorium](https://github.com/Mar0dev/LilyGo-TTGO-Examples), które powstało w celach niniejszego projektu.

1. **downloadMalware.ino** - skrypt ten automatyzuje serię wejść klawiatury, aby uruchomić PowerShell jako administrator, połączyć się ze zdalnym serwerem, pobrać plik, zmienić jego nazwę, wykonać go i potencjalnie usunąć po wykonaniu. Może on zostać wykorzystany przez atakującego do umieszczenia i uruchomienia Malware na komputerze ofiary.

    Poniżej znajduje się podział funkcjonalności skryptu krok po kroku:

> 1. Skrypt zawiera niezbędną bibliotekę Keyboard.h, umożliwiającą emulację klawiatury.
> 2. Deklarowane są zmienne określające szczegóły połączenia z serwerem kontrolowanym przez atakującego, skąd pobrane zostanie oprogramowanie (zmienne takie jak nazwa użytkownika, hasło, ścieżka do pliku, nazwa pliku i adres IP serwera). Dodatkowo definiowane są zmienne dla lokalnej ścieżki i nazwy zapisu.
> 3. Wywoływana jest funkcja "setup()", która inicjalizuje klawiaturę i rozpoczyna emulację klawiatury.
> 4. Aby uruchomić PowerShell jako administrator, wykonywane są różne polecenia klawiaturowe. Obejmuje to naciśnięcie klawisza Windows, wpisanie "r" w celu otwarcia okna dialogowego Uruchom i wpisanie "powershell" w celu uruchomienia PowerShell.
> 5. Dodatkowe polecenia klawiaturowe są wysyłane w celu symulacji naciśnięcia kombinacji klawiszy Ctrl+Shift+Enter w celu uruchomienia PowerShell jako administrator.
> 6. Polecenie jest konstruowane w celu pobrania pliku ze zdalnego serwera przy użyciu polecenia "scp" z określonymi poświadczeniami serwera, ścieżką pliku i nazwą pliku. Polecenie jest wysyłane za pomocą emulacji klawiatury wraz z czynnością uwierzytelnienia, po czym następuje pobranie pliku.
> 7. Polecenia klawiaturowe są wysyłane w celu zmiany nazwy pobranego pliku za pomocą polecenia "Rename-Item" PowerShell.
> 8. Skrypt symuluje wykonanie pliku .exe o zmienionej nazwie przy użyciu polecenia PowerShell "Start-Process".
> 9. Wprowadzane jest opóźnienie wynoszące 3 sekundy, aby zapewnić czas na wykonanie pliku .exe.
> 10. Jeśli flaga "checkDelete" ma wartość true, wysyłane są polecenia klawiaturowe w celu usunięcia pobranego pliku za pomocą polecenia PowerShell "Remove-Item".
> 11. Funkcja "Keyboard.end()" jest wywoływana w celu zwolnienia zasobów klawiatury.

2. **processorOverloading.ino** - skrypt ten automatycznie tworzy pierwszy plik batch, który następnie jest replikowany na komputerze ofiary, co powoduje zużycie wszystkich zasobów komputera i pojawienia się Blue Screen of Death.

    Poniżej znajduje się działanie kodu krok po kroku:
    
> 1. Skrypt zawiera bibliotekę Keyboard.h, która pozwala na emulację wciśnięć na klawiaturze.
> 2. W kilku kolejnych linijkach kodu włączana jest konsola na systemie Windows, z której to będzie można wykonać resztę skryptu na komputerze ofiary.
> 3. Celem kolejnej części kodu jest utworzenie pliku batch z kodem, który pozwala na powielanie plików. Jest to robione za pomocą komendy Keyboard.println.
> 4. Po stworzeniu pliku w konsoli cmd na komputerze ofiary jest odpalany plik ze złośliwym kodem, który poprzez wielokrotną duplikację zabiera wszystkie zasoby komputera i powoduje pojawienie się Blue Screen of Death.
> 5. Na sam koniec następuje zakończenie pracy urządzenia poprzez zakończenie "Keyboard.end()".

3. **restartComputer.ino** - skrypt automatyzuje szereg działań, które obejmują uruchamianie określonych poleceń w wierszu polecenia systemu Windows w celu zainicjowania ponownego uruchomienia systemu z flagą wymuszenia.

    Poniżej znajduje się podział funkcjonalności kodu:

> 1. Kod zawiera niezbędną bibliotekę Keyboard.h, aby umożliwić emulację klawiatury. Wywoływana jest funkcja "setup()", która inicjalizuje klawiaturę i rozpoczyna jej emulację. Wykonywane są podstawowe polecenia klawiaturowe, które skutkują uruchomienie cmd systemu Windows.
> 2. Dodatkowe polecenia klawiaturowe symulują wpisanie polecenia "shutdown -r -f -t 10" w wierszu polecenia. Polecenie to nakazuje komputerowi zainicjowanie ponownego uruchomienia systemu (-r) po opóźnieniu wynoszącym 10 sekund (-t 10) z flagą force (-f), aby wymusić zamknięcie wszystkich uruchomionych aplikacji.
> 3. Skrypt symuluje naciśnięcie klawisza Enter w celu wykonania polecenia "shutdown", a następnie funkcja "Keyboard.end()" jest wywoływana w celu zwolnienia zasobów klawiatury.

4. **stealCookies.ino** - skrypt automatyzuje proces kopiowania plików cookie z określonych przeglądarek (Chrome, Firefox i Edge) na komputerze lokalnym na zdalny serwer za pośrednictwem protokołu Secure Copy Protocol (SCP).

    Poniżej znajduje się podział funkcjonalności kodu:

> 1. Wykonują się podstawowe operacje inicjalizujące skrypt (funkcja inicjalizująca emulację klawiatury, uruchomienie cmd)
> 2. Skrypt sprawdza wartość zmiennych boolean dla każdej przeglądarki (chrome, firefox, edge) i kontynuuje kopiowanie plików cookie, jeśli flaga odpowiedniej przeglądarki jest ustawiona na 1 (true). Dla każdej wybranej przeglądarki skrypt wprowadza określoną ścieżkę folderu na komputerze lokalnym, w którym przechowywane są pliki cookie przeglądarki. Następnie wywołuje funkcję "copyCookies()" z odpowiednią ścieżką jako argumentem. Wewnątrz funkcji "copyCookies()" wykonywane są polecenia klawiaturowe symulujące otwarcie wiersza poleceń (CMD) i wprowadzenie polecenia "scp" w celu zainicjowania procesu kopiowania. Polecenie zawiera ścieżkę pliku cookie, szczegóły połączenia z serwerem i ścieżkę docelową na serwerze.
> 3. Następuje zwolnienie zasobów skryptu.

5. **stealPasswd.ino** - skrypt automatyzuje proces kopiowania pliku "/etc/passwd" z lokalnego komputera na zdalny serwer za pośrednictwem protokołu Secure Copy Protocol (SCP).

    Poniżej znajduje się podział funkcjonalności kodu:
> 1. Po podłączeniu urządzenia USB kod jest inicjalizowany.
> 2. Skrypt wykorzystuje funkcję Keyboard.println() do symulacji wpisywania polecenia SCP w celu skopiowania pliku "/etc/passwd" na zdalny serwer. Polecenie zawiera ścieżkę do pliku, szczegóły połączenia z serwerem i ścieżkę docelową na serwerze.
> 3. Następuje zwolnienie zasobów skryptu.

6. **stealWiFiPassword.ino** wraz z **WiFiStealer.PS1** - dostarczony kod pobiera skrypt Powershell ze zdalnego źródła, a następnie go wykonuje na komputerze ofiary. Skrypt Powershell pobiera listę zapisanych sieci wifi wraz z ich hasłami, a następnie wysyła je na serwer atakującego.

    Poniżej znajduje się opis działania kodu:
> 1. Po podłączeniu urządzenia USB kod jest inicjalizowany.
> 2. Skrypt używa funkcji Keyboard.println() do symulacji wpisywania polecenia PowerShell w oknie dialogowym Uruchom. Polecenie obejmuje ustawienie zasad wykonywania na RemoteSigned, pobranie skryptu z określonego adresu URL i wykonanie pobranego skryptu.
> 3. Skrypt Powershell pobiera zapisane hasła Wi-Fi i wysyła je na serwer. Używa polecenia "netsh wlan export profile key=clear", aby wyeksportować profile Wi-Fi z hasłami w postaci czystego tekstu. Następnie iteruje przez wszystkie pliki XML w katalogu, wyodrębnia SSID (nazwę sieci Wi-Fi) i informacje o haśle z każdego pliku XML i konstruuje adres URL z adresem IP serwera oraz wartościami SSID i hasła. Na koniec używa cmdletu Invoke-WebRequest do wysłania żądania do skonstruowanego adresu URL,  w celu wysłania informacji o Wi-Fi do określonego serwera.
> 4. Usuwa wszystkie pliki powstałe w wyniku wyżej wymienionych informacji, celem zacierania śladów.
> 5. Następuje zwolnienie zasobów skryptu.

7. **stealWifiConfig.ino** - skrypt pobiera profile WiFi, a następnie wysyła je na serwer atakującego. Jest inną wariacją skryptu opisanego w 6. punkcie.

    Poniżej znajduje się opis działania kodu:
> 1. Po podłączeniu urządzenia USB kod jest inicjalizowany.
> 2. Używa polecenia "netsh wlan show profile * key=clear > data.txt", aby pobrać profile Wi-Fi w postaci czystego tekstu i zapisać dane wyjściowe w pliku o nazwie "data.txt". Tworzy polecenie SCP (Secure Copy) w celu skopiowania pliku "data.txt" na zdalny serwer. Polecenie zawiera użytkownika serwera, adres IP, ścieżkę i nazwę kopiowanego pliku. Wysyła to polecenie.
> 3. Używa polecenia "del /f data.txt", aby usunąć plik "data.txt".
> 4. Następuje zwolnienie zasobów skryptu.

# Działania naprawcze/prewencyjne

Ochrona przed atakami złęgo USB może być trudna. Najlepsze praktyki obejmują m.in.:

+ Podłączanie tylko zaufanych urządzeń do portu USB.
+ Wykorzystanie przejściówek USB, uniemożliwiających tego typu ataki.
+ Aktualizacja OS i Software, celem wyeliminowania znanych luk bezpieczeństwa.
+ Utwardzanie systemu (np. niektóre skrypty wymagały uprawnień administratora do działania - zablokowanie tego profilu skutecznie uniemożliwi ich pomyślne wykonanie)
+ Zwiększanie świadomości użytkowników na tego typu ataki
+ Wyłączenie funkcję automatycznego uruchamiania USB, aby zapobiec automatycznemu wykonywaniu programów po podłączeniu urządzenia USB. Można to zrobić za pomocą ustawień systemowych lub oprogramowania zabezpieczającego.
+ Wdrożenie rozwiązań bezpieczeństwa punktów końcowych, które mogą wykrywać i łagodzić ataki oparte na USB. Rozwiązania te mogą obejmować takie funkcje, jak kontrola urządzeń USB, white-listy, monitorowanie zachowania, wykrywanie anomalii, reagowanie na incydenty.

# Wnioski

Urządzenia emulujące wejścia klawiatury mogą zostać wykorzystane do automatyzacji repetytywnych czynności, które wymagają jej użycia. Można je zaprogramować do szybkiego wykonywania złożonych sekwencji klawiszy, co pozwala zaoszczędzić czas i zwiększyć wydajność pracy. Oprócz tego, badacze bezpieczeństwa mogą ich używać do oceny bezpieczeństwa systemów. Wstrzykując predefiniowane naciśnięcia klawiszy, może wykonywać zadania, takie jak przechwytywanie haseł, eskalacja uprawnień lub uruchamianie innych testów bezpieczeństwa. Dodatkowo, mogą być wykorzystywane jako część ataku socjotechnicznego w celu wykorzystania ludzkich słabości, jako element programu mającego na celu podniesienie świadomości organizacji względem bezpieczeństwa. Są cennym narzędziem do celów edukacyjnych, umożliwiając użytkownikom zrozumienie i eksperymentowanie z atakami polegającymi na wstrzykiwaniu naciśnięć klawiszy, poznanie luk w zabezpieczeniach i opracowanie mechanizmów obrony przed nimi. Należy jednak wspomnieć, że pomimo wielu korzyści płynących z wyżej wymienionych elementów, urządzenia tego typu mogą być użyte do złośliwych celów przez cyberprzestępców. Implementując środki zaradcze opisane w poprzedniej części niniejszej pracy można skutecznie zmniejszyć wektor i konsekwencje takich ataków.
