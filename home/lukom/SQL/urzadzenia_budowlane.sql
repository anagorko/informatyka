USE urzadzenia_budowlane;

DROP TABLE IF EXISTS sprzet;

CREATE TABLE sprzet(
id_sprzetu INT,
nazwa_sprzetu VARCHAR(100),
koszt_wynajecia DOUBLE,
kaucja DOUBLE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/109/sprzet_budowlany.txt'
INTO TABLE sprzet LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS klienci;       

CREATE TABLE klienci(  
nr_dowodu_osoby VARCHAR(100),
imie VARCHAR(100),
nazwisko VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/109/klienci.txt'
INTO TABLE klienci LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS wynajem;       

CREATE TABLE wynajem(  
data_wypozycz DATE,
data_zwrotu DATE,
id_sprzetu INT,
transport_km DOUBLE,
nr_dowodu_osoby VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/109/wynajem.txt'
INTO TABLE wynajem LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


#109.1
/*
SELECT sprzet.nazwa_sprzetu, COUNT(*) AS wypozyczenia 
FROM wynajem
	JOIN sprzet ON sprzet.id_sprzetu = wynajem.id_sprzetu
GROUP BY wynajem.id_sprzetu
ORDER BY wypozyczenia DESC
LIMIT 1;
*/
#109.2
/*
SELECT nr_dowodu_osoby, SUM(kaucja)
FROM wynajem
	JOIN sprzet ON sprzet.id_sprzetu = wynajem.id_sprzetu
WHERE nr_dowodu_osoby = 'JCK343973';
*/
#109.3
/*
SELECT imie, nazwisko, COUNT(distinct id_sprzetu) as ilosc
FROM wynajem
	JOIN klienci ON klienci.nr_dowodu_osoby = wynajem.nr_dowodu_osoby
WHERE YEAR(data_wypozycz) = 2014
GROUP BY klienci.nr_dowodu_osoby
HAVING ilosc > 3
ORDER BY ilosc DESC;
*/
#109.4
/*
SELECT count(*) as ilosc
FROM klienci
WHERE nr_dowodu_osoby NOT IN 
	(SELECT nr_dowodu_osoby
	FROM wynajem
	GROUP BY nr_dowodu_osoby);
*/
#109.5
#a)
/*
SELECT MONTH(data_wypozycz) as miesiac, SUM(koszt_wynajecia * DATEDIFF(data_zwrotu, data_wypozycz)) as przychod_z_wyporzyczen
FROM wynajem
	JOIN sprzet ON sprzet.id_sprzetu = wynajem.id_sprzetu
GROUP BY miesiac;
*/
#b)
/*
SELECT MONTH(data_wypozycz) as miesiac, SUM( CASE WHEN transport_km = 0 THEN 0 WHEN transport_km <= 10 THEN 50 ELSE 100 END) AS przychod_z_transportu  
FROM wynajem
        JOIN sprzet ON sprzet.id_sprzetu = wynajem.id_sprzetu
GROUP by miesiac;
*/

