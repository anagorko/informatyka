USE rosliny_ogrodowe;

DROP TABLE IF EXISTS osoby;
CREATE TABLE osoby
(
	id_klienta INT,
	nazwisko VARCHAR(100),
	imie VARCHAR(100),
	miasto VARCHAR(100)
);
LOAD DATA LOCAL INFILE '../../../zbior_zadan/105/osoby.txt' INTO TABLE osoby FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS rosliny;
CREATE TABLE rosliny
(
	id_rosliny INT,
	nazwa VARCHAR(100),
	cena INT,
	kolory VARCHAR(100),
	okres VARCHAR(100),
	rozmiary VARCHAR(100)
);
LOAD DATA LOCAL INFILE '../../../zbior_zadan/105/rosliny.txt' INTO TABLE rosliny FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS zamowienia;
CREATE TABLE zamowienia
(
	lp INT,
	id_klienta INT,
	data DATE,
	ilosc INT,
	id_rosliny INT
);
LOAD DATA LOCAL INFILE '../../../zbior_zadan/105/zamowienia.txt' INTO TABLE zamowienia FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;



#105.1
/*SELECT COUNT( * ) as ile_faktur
FROM (SELECT *
	FROM zamowienia
	GROUP BY data, id_klienta) as faktury;

SELECT MAX( koszt_faktury ) as max_faktura
FROM (SELECT lp, SUM( koszt ) as koszt_faktury
	FROM (SELECT lp, data, id_klienta, (ilosc * cena) as koszt
		FROM zamowienia, rosliny
		WHERE rosliny.id_rosliny = zamowienia.id_rosliny) as koszt_zamiowienia
	GROUP BY data, id_klienta) as faktury;

SELECT COUNT( * ) as ile_klientow
FROM (SELECT id_klienta, COUNT( DISTINCT data ) as ile
	FROM zamowienia
	GROUP BY id_klienta) as faktury
WHERE ile > 1;


#105.2
SELECT miasto, COUNT( * )
FROM zamowienia, osoby, rosliny
WHERE zamowienia.id_klienta = osoby.id_klienta
AND zamowienia.id_rosliny = rosliny.id_rosliny
AND okres LIKE 'VII-VIII'
GROUP BY miasto;


#105.3
SELECT nazwisko, imie, ilosc, nazwa
FROM osoby, rosliny, zamowienia
WHERE osoby.id_klienta = zamowienia.id_klienta
AND rosliny.id_rosliny = zamowienia.id_rosliny
AND kolory LIKE 'bialo-liliowe'
AND ilosc > 10;


#105.4
SELECT nazwa
FROM rosliny
WHERE rosliny.id_rosliny NOT IN (SELECT id_rosliny 
				FROM zamowienia
				GROUP BY id_rosliny);
*/

SELECT rozmiary, COUNT( lp )
FROM zamowienia, rosliny
WHERE rosliny.id_rosliny = zamowienia.id_rosliny
GROUP BY rozmiary;