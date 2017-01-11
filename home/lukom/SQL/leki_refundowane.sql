USE leki_refundowane;

DROP TABLE IF EXISTS recepty;

CREATE TABLE recepty(
id_recepty VARCHAR(100),
data DATE,
kod_leku VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/104/recepty.txt'
INTO TABLE recepty FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS leki_refundowane; 

CREATE TABLE leki_refundowane( 
kod_leku VARCHAR(100),
subs_czynna VARCHAR(100),
nazwa VARCHAR(100),
id_grupy VARCHAR(100),
cena_detaliczna DOUBLE,
cena_refundowana DOUBLE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/104/leki_refundowane.txt'
INTO TABLE leki_refundowane FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS grupy_lekow; 

CREATE TABLE grupy_lekow( 
id_grupy VARCHAR(100),
nazwa_grupy VARCHAR(200)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/104/grupy_lekow.txt'
INTO TABLE grupy_lekow FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

#104.1
/*
SELECT data, COUNT(distinct id_recepty) AS ilosc_recept
FROM recepty
GROUP BY data
ORDER BY ilosc_recept
LIMIT 1;
*/
#104.2
/*
SELECT nazwa_grupy
FROM leki_refundowane
	JOIN grupy_lekow ON leki_refundowane.id_grupy = grupy_lekow.id_grupy
WHERE cena_refundowana = 0;
*/
#104.3
/*
SELECT MONTH(recepty.data) AS miesiac, COUNT(distinct recepty.id_recepty) AS ilosc_recept, SUM(cena_detaliczna) AS wartosc_lekow
FROM recepty
	JOIN leki_refundowane ON recepty.kod_leku = leki_refundowane.kod_leku
GROUP BY miesiac;
*/
#104.4
/*
SELECT nazwa, cena_detaliczna, nazwa_grupy
FROM recepty
	JOIN leki_refundowane ON recepty.kod_leku = leki_refundowane.kod_leku
	JOIN grupy_lekow ON grupy_lekow.id_grupy = leki_refundowane.id_grupy
ORDER BY cena_detaliczna DESC
LIMIT 1;
*/
#104.5
/*
SELECT data, id_recepty, (SUM(cena_detaliczna) - SUM(cena_refundowana)) AS suma_doplat
FROM recepty
	JOIN leki_refundowane ON leki_refundowane.kod_leku = recepty.kod_leku
GROUP BY id_recepty
HAVING suma_doplat > 2000
ORDER BY data;
*/
