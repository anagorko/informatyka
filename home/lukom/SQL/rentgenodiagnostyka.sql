USE rentgenodiagnostyka;

DROP TABLE IF EXISTS pacjenci;

CREATE TABLE pacjenci(
pesel VARCHAR(100),
nazwisko VARCHAR(100),
imie VARCHAR(100),
plec VARCHAR(1),
nfz VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/103/pacjenci.txt'
INTO TABLE pacjenci FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS badania;

CREATE TABLE badania(
pesel VARCHAR(100),
id_badania VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/103/badania.txt'
INTO TABLE badania FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS rtg;

CREATE TABLE rtg(
id_badania VARCHAR(100),
nazwa_badania VARCHAR(100),
cena_badania DOUBLE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/103/rtg.txt'
INTO TABLE rtg FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


#103.1
/*
SELECT nazwisko, imie,  CAST(SUBSTR(pacjenci.pesel, 1, 2) AS INT) + 1900 AS rok
FROM badania
	JOIN pacjenci ON pacjenci.pesel = badania.pesel
GROUP BY pacjenci.pesel;
*/
#103.2
/*
SELECT nfz, sum(cena_badania) as suma_kosztow
FROM badania
	JOIN pacjenci ON pacjenci.pesel = badania.pesel
	JOIN rtg ON rtg.id_badania = badania.id_badania
GROUP BY nfz
ORDER BY suma_kosztow DESC;
*/
#103.3
/*
#a)
SELECT rtg.nazwa_badania, COUNT(*) AS ilosc_razy
FROM badania
	JOIN rtg ON badania.id_badania = rtg.id_badania
GROUP BY rtg.id_badania
ORDER BY ilosc_razy DESC
LIMIT 1;
#b)
SELECT nazwa_badania, COUNT(distinct pesel) AS ilosc_pacjentow
FROM badania
	JOIN rtg ON badania.id_badania = rtg.id_badania
GROUP BY rtg.id_badania
ORDER BY ilosc_pacjentow DESC
LIMIT 1;
*/
#103.4
/*
SELECT plec, COUNT(distinct badania.pesel) AS ilosc
FROM badania
	JOIN pacjenci ON badania.pesel = pacjenci.pesel
GROUP BY plec;
*/
#103.5
/*
SELECT FLOOR(SUBSTR(pesel,1,2)/10) * 10 + 1900 AS dziesieciolecie, COUNT(*) AS liczba_pacjentow
FROM pacjenci
GROUP BY dziesieciolecie;
*/
