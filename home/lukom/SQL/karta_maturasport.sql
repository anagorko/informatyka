 USE karta_maturasport;

DROP TABLE IF EXISTS osoby;

CREATE TABLE osoby(
id_uzytkownika INT,
nazwisko VARCHAR(100),
imie VARCHAR(100),
plec VARCHAR(1)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/101/osoby.txt'
INTO TABLE osoby FIELDS TERMINATED BY ';' IGNORE 1 LINES;

DROP TABLE IF EXISTS zajecia;

CREATE TABLE zajecia(
id_zajec INT,
obiekt VARCHAR(100),
zajecia VARCHAR(100),
koszt DOUBLE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/101/zajecia.txt'
INTO TABLE zajecia FIELDS TERMINATED BY ';' IGNORE 1 LINES;

DROP TABLE IF EXISTS wejscia;

CREATE TABLE wejscia(
lp INT,
id_uzytkownika INT,
data DATE,
id_zajec INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/101/wejscia.txt'
INTO TABLE wejscia FIELDS TERMINATED BY ';' IGNORE 1 LINES;

#101.1
/*
SELECT COUNT(distinct id_uzytkownika)
FROM wejscia;
*/
#101.2
/*
SELECT obiekt, SUM(koszt) AS koszt
FROM zajecia
	JOIN wejscia ON zajecia.id_zajec = wejscia.id_zajec
GROUP BY obiekt;
*/
#101.3
/*
SELECT nazwisko, imie
FROM wejscia
	JOIN osoby ON osoby.id_uzytkownika = wejscia.id_uzytkownika
WHERE MONTH(data) = 4 AND DAY(data) = 16 AND YEAR(data) = 2014
GROUP BY wejscia.id_uzytkownika
HAVING COUNT(wejscia.id_uzytkownika) > 1;
*/
#101.4
/*
SELECT zajecia, COUNT(zajecia) AS 'liczba_osob', obiekt
FROM zajecia
	JOIN wejscia ON wejscia.id_zajec = zajecia.id_zajec
GROUP BY zajecia
ORDER BY liczba_osob DESC LIMIT 1;
*/
#101.5
/*
SELECT obiekt, COUNT(*) AS liczba_wejsc
FROM zajecia
	JOIN wejscia ON zajecia.id_zajec = wejscia.id_zajec
GROUP BY obiekt
ORDER BY obiekt;
*/
