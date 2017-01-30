USE rosliny_ogrodowe;

DROP TABLE IF EXISTS osoby;
CREATE TABLE osoby(
id_klienta INT,
nazwisko VARCHAR(100),
imie VARCHAR(100),
miasto VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/105/osoby.txt'
INTO TABLE osoby FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS rosliny;
CREATE TABLE rosliny(
id_rosliny INT,
nazwa VARCHAR(100),
cena DOUBLE, 
kolor VARCHAR(100),
okres_kwitnienia VARCHAR(100),
rozmiar_doniczki VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/105/rosliny.txt'
INTO TABLE rosliny FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS zamowienia;
CREATE TABLE zamowienia(
lp INT,
id_klienta INT,
data DATE,
liczba_sadzonek INT,
id_rosliny INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/105/zamowienia.txt'
INTO TABLE zamowienia FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


#105.1
/*
SELECT SUM(x.ilosc_faktor), MAX(najwyzsza_faktora)
FROM
	(SELECT  data, COUNT( distinct id_klienta) AS ilosc_faktor, MAX(zamowienia.liczba_sadzonek * rosliny.cena) AS najwyzsza_faktora 
	FROM zamowienia
		JOIN rosliny ON rosliny.id_rosliny = zamowienia.id_rosliny
	GROUP BY data
	ORDER BY data,id_klienta)x;
*/
#105.2
/*
SELECT miasto, COUNT(*) AS ilosc_zamowien
FROM zamowienia
	JOIN osoby ON osoby.id_klienta = zamowienia.id_klienta
	JOIN rosliny ON rosliny.id_rosliny = zamowienia.id_rosliny
WHERE rosliny.okres_kwitnienia = 'VII-VIII'
GROUP BY osoby.miasto;
*/
#105.3
/*
SELECT nazwisko, imie, liczba_sadzonek, nazwa
FROM zamowienia
	JOIN osoby ON osoby.id_klienta = zamowienia.id_klienta
        JOIN rosliny ON rosliny.id_rosliny = zamowienia.id_rosliny
WHERE liczba_sadzonek >=10
	AND kolor = 'bialo-liliowe';
*/
#105.4
/*
SELECT nazwa
FROM rosliny
WHERE id_rosliny NOT IN
	(SELECT id_rosliny
	FROM zamowienia
	GROUP BY id_rosliny
	ORDER BY id_rosliny);
*/
#105.5

SELECT rozmiar_doniczki, COUNT(*) AS liczba_zamowien
FROM zamowienia
	JOIN rosliny ON rosliny.id_rosliny = zamowienia.id_rosliny
GROUP BY rozmiar_doniczki
ORDER BY rozmiar_doniczki;


 







