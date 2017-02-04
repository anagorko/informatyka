USE loty_pasazerskie;

DROP TABLE IF EXISTS loty;

CREATE TABLE loty(
id_lotu INT,
miejsce_docelowe VARCHAR(100),
data DATE,
godzina TIME
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/107/loty.txt'
INTO TABLE loty LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS pasazerowie;

CREATE TABLE pasazerowie(
id_pasazera INT,
nazwisko VARCHAR(100),
imie VARCHAR(100),
adres VARCHAR(100),
miejscowosc VARCHAR(100),
telefon VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/107/pasazerowie.txt'
INTO TABLE pasazerowie LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS bilety;

CREATE TABLE bilety(
id_lotu INT,
id_pasazera INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/107/bilety.txt'
INTO TABLE bilety LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

#107.1
/*
SELECT x.miejsce_docelowe, COUNT(x.miejsce_docelowe) AS ilosc_dni
FROM 
	(SELECT miejsce_docelowe
	FROM loty
	GROUP BY miejsce_docelowe, data)x 
GROUP BY x.miejsce_docelowe
ORDER BY ilosc_dni DESC
LIMIT 3;
*/
#107.2
/*
SELECT nazwisko, imie, COUNT(*) AS liczba_biletow
FROM bilety
	JOIN pasazerowie ON pasazerowie.id_pasazera = bilety.id_pasazera
GROUP BY bilety.id_pasazera
HAVING liczba_biletow > 15
ORDER BY liczba_biletow;
*/
#107.3
/*
SELECT MONTH(data) AS miesiac, COUNT(*) AS liczba_biletow
FROM bilety
	JOIN pasazerowie ON pasazerowie.id_pasazera = bilety.id_pasazera
	JOIN loty ON loty.id_lotu = bilety.id_lotu
WHERE pasazerowie.miejscowosc = 'Wroclaw'
GROUP BY miesiac;
*/
#107.4
/*
SELECT imie, nazwisko, godzina
FROM bilety
	JOIN pasazerowie ON pasazerowie.id_pasazera = bilety.id_pasazera
        JOIN loty ON loty.id_lotu = bilety.id_lotu
WHERE miejsce_docelowe LIKE 'Londyn%'
	AND godzina >= '8:00'
	AND godzina <= '10:00'
ORDER BY nazwisko;
*/
#107.5
/*
SELECT id_lotu, miejsce_docelowe
FROM loty
WHERE id_lotu NOT IN 
	(SELECT id_lotu
	FROM bilety);
*/
