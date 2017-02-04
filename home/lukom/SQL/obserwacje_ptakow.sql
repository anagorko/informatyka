USE obserwacje_ptakow;

DROP TABLE IF EXISTS gatunki;

CREATE TABLE gatunki(
id_gatunku INT,
nazwa_zwyczajowa VARCHAR(100),
nazwa_lacinska VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/106/gatunki.txt'
INTO TABLE gatunki LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS lokalizacje;

CREATE TABLE lokalizacje(
id_lokalizacji INT,
lokalizacja VARCHAR(100),
powiat VARCHAR(100),
opis VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/106/lokalizacje.txt'
INTO TABLE lokalizacje LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS obserwacje;

CREATE TABLE obserwacje(
id_gatunku INT,
id_lokalizacji INT,
poczatek DATETIME,
koniec DATETIME,
liczebnosc INT,
zachowanie VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/106/obserwacje.txt'
INTO TABLE obserwacje LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

#106.1
/*
SELECT COUNT(*) AS ilosc_pomiarow, nazwa_zwyczajowa 
FROM obserwacje
	JOIN gatunki ON gatunki.id_gatunku = obserwacje.id_gatunku
GROUP BY obserwacje.id_gatunku
ORDER BY ilosc_pomiarow DESC
LIMIT 3;
*/
#106.2
#korzystam z faktu, że oberwacje zaczynają się i kończą w tym samym miesiącu 
/*
SELECT  MONTH(obserwacje.poczatek) AS miesiac, count(*) as liczba_obserwacji
FROM obserwacje
	JOIN gatunki ON gatunki.id_gatunku = obserwacje.id_gatunku
WHERE nazwa_zwyczajowa = 'remiz'
GROUP BY miesiac
ORDER BY miesiac;
*/
#106.3
/*
SELECT nazwa_zwyczajowa, COUNT(*) as ile
FROM obserwacje
	JOIN gatunki ON gatunki.id_gatunku = obserwacje.id_gatunku
	JOIN lokalizacje ON lokalizacje.id_lokalizacji = obserwacje.id_lokalizacji
WHERE nazwa_lacinska LIKE '%Corvus%'
	AND opis LIKE '%miasto%'
GROUP BY gatunki.id_gatunku;
*/
#106.4
#a)
/*
SELECT lokalizacja, poczatek, MINUTE(TO_SECONDS(koniec) - TO_SECONDS(poczatek)) AS czas, COUNT(*) AS liczba_osobnikow
FROM obserwacje
	JOIN lokalizacje ON lokalizacje.id_lokalizacji = obserwacje.id_lokalizacji
GROUP BY lokalizacja, poczatek, koniec
ORDER BY czas DESC LIMIT 1;
*/
#b)
/*
SELECT lokalizacja, poczatek AS data,TRUNCATE(COUNT(*)/MINUTE(TO_SECONDS(koniec) - TO_SECONDS(poczatek)),3) AS sprawnosc
FROM obserwacje
        JOIN lokalizacje ON lokalizacje.id_lokalizacji = obserwacje.id_lokalizacji
GROUP BY lokalizacja, poczatek, koniec 
ORDER BY sprawnosc DESC
LIMIT 1;
*/
#106.5
#a)
/*
SELECT COUNT(*) AS liczba_zaobserwowanych_osobnikow
FROM obserwacje
	JOIN gatunki ON gatunki.id_gatunku = obserwacje.id_gatunku
WHERE nazwa_zwyczajowa = 'zuraw'
*/
#b)
/*
SELECT powiat,zachowanie, COUNT(*) AS ilosc_osobnikow
FROM obserwacje
	JOIN gatunki ON gatunki.id_gatunku = obserwacje.id_gatunku
	JOIN lokalizacje ON lokalizacje.id_lokalizacji = obserwacje.id_lokalizacji
WHERE nazwa_zwyczajowa = 'zuraw'
GROUP BY powiat, zachowanie;
*/
