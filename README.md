# Game---Rhombus-vs-hexagons

Pe scurt, jocul se va desfășura în cadrul a 3 linii, cu 3 coloane fiecare. Din partea dreaptă, din afara ecranului, apar la intervale aleatoare de timp inamici “răi” de tip hexagon ce parcurg o linie până în partea stângă a ecranului. Odată ce un hexagon parcurge toată linia, jucătorul pierde o viață :( . La 3 vieți pierdute, jocul este pierdut.

Pentru a combate hexagoanele rele :(, jucătorul are posibilitatea de a plasa într-una din cele 3 celule de pe fiecare linie, un romb salvator care lansează proiectile ce se deplasează în partea dreaptă, de-alungul liniei în care se află rombul ce a lansat proiectilul. Odată întâlnit un hexagon, proiectilul îi creează daune și la 3 proiectile atinse, hexagonul dispare și situația este salvată pentru moment <3.

Cu toate acestea, jucătorul are 2 inconveniente :( . El nu poate plasa oricâte romburi dorește, deoarece fiecare romb plasat costă un anumit număr de steluțe. Acestea apar la intervale aleatoare în scenă și jucătorul trebuie să le strângă. În plus, fiecare romb poate răni doar un anumit tip de hexagon, pe baza culorii pe care o are fiecare.

Reguli generale de joc
Plasare romb în scena de joc
Jocul are un comportament bazat pe culori. Sunt 4 tipuri de triplete romb-proiectil-inamic, fiecare triplet de aceeași culoare de bază. În exemplul nostru, am ales culorile portocaliu, albastru, galben și mov. Voi puteți să alegeți alte culori.

Vom numi romburi, din acest moment până la final, elementele plasate de jucător.

În interfața grafică cu utilizatorul, sau GUI, în partea stânga-sus a ecranului, se regăsesc 4 chenare, cu câte un tip de romb în fiecare. Prin procesul de drag & drop, descris mai jos, se selectează un anumit tip de romb și se plasează într-una din celulele de joc valide, în care nu se regăsește niciun alt romb.

Jucatorului i se va permite selecția unui tip de romb, doar dacă acesta are resurse suficiente pentru plasarea tipului respectiv. Numărul de resurse stabilit de noi este:

O steluță pentru rombul de culoare portocalie
2 steluțe pentru rombul de culoare albastră
2 steluțe pentru rombul de culoare galbenă
3 steluțe pentru rombul de culoare mov
Steluțele apar în scenă la intervale aleatoare. Noi am ales să apară câte 3 odată. Jucătorul poate selecta o steluță când cursorul se află în interiorul ei și apasă butonul stânga de la mouse. Odată selectată o steluță, i se adaugă la numărul de steluțe pe care îl are strâns până în acel moment.

Comportament romburi și inamici
Din partea dreaptă, la intervale aleatoare de timp, se deplasează un inamic de-alungul unei linii alese aleator. Inamicul face parte din unul din cele 4 tipuri posibile. În situația în care un romb de același tip se regăsește într-una din cele 3 celule ale liniei, acesta începe să lanseze proiectile la intervale regulate. În situația în care un romb nu are un inamic de același tip cu el pe linie, rombul respectiv nu lansează proiectile, chiar dacă pe linie sunt inamici de alte tipuri.
