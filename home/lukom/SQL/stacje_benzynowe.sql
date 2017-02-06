USE stacje_benzynowe;

DROP TABLE IF EXISTS drogi;

CREATE TABLE drogi(
id_drogi INT,
nazwa VARCHAR(100),
dlugosc INT,
id_kategorii VARCHAR(1)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/108/drogi.txt'
INTO TABLE drogi LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS kategorie;

CREATE TABLE kategorie(
id_kategorii VARCHAR(1),
kategoria VARCHAR(100) 
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/108/kategorie.txt'
INTO TABLE kategorie LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS sieci;

CREATE TABLE sieci(
id_sieci INT,
nazwa_sieci VARCHAR(100) 
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/108/sieci.txt'
INTO TABLE sieci LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS stacje;

CREATE TABLE stacje(
id_stacji INT,
id_drogi INT,
id_sieci INT 
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/108/stacje.txt'
INTO TABLE stacje LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

#108.1
/*
SELECT SUM(dlugosc)
FROM drogi;
*/
#108.2
/*
SELECT nazwa, dlugosc
FROM drogi
WHERE id_drogi NOT IN
	(SELECT id_drogi
	FROM stacje)
ORDER BY dlugosc DESC
LIMIT 1;
*/
#108.3
/*
SELECT drogi.id_drogi, nazwa, COUNT(*) AS ilosc_stacji, ROUND(dlugosc/COUNT(*),1) AS sr_odl
FROM drogi
	JOIN stacje ON stacje.id_drogi = drogi.id_drogi
GROUP BY drogi.id_drogi
ORDER BY sr_odl
LIMIT 1;
*/
#108.4
/*
SELECT nazwa, kategoria
FROM drogi
	JOIN kategorie ON kategorie.id_kategorii = drogi.id_kategorii
WHERE nazwa LIKE '%autostrada%'
	AND kategoria NOT LIKE 'autostrada';
*/
#108.5
#wydaje mi się , że odpowiedzi nie uwzględniaja wszystkich danych
/*
SELECT nazwa_sieci, kategoria, COUNT(*) AS ilosc
FROM sieci
	JOIN stacje ON stacje.id_sieci = sieci.id_sieci
	JOIN drogi ON drogi.id_drogi = stacje.id_drogi
	JOIN kategorie ON kategorie.id_kategorii = drogi.id_kategorii
GROUP BY sieci.id_sieci, kategorie.id_kategorii
ORDER BY sieci.nazwa_sieci, kategoria;
*/
