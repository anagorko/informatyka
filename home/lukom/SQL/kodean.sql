USE kodean;

DROP TABLE IF EXISTS towary;

CREATE TABLE towary(
nazwa VARCHAR(100),
rodzaj VARCHAR(100),
masa INT,
vat VARCHAR(100),
EAN VARCHAR(13)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/112/towary.txt'
INTO TABLE towary LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS kraje;

CREATE TABLE kraje(
kod_kraju VARCHAR(100),
kraj VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/112/kraje.txt'
INTO TABLE kraje LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS producenci;

CREATE TABLE producenci(
kod_kraju VARCHAR(100),
kod_oddzialu VARCHAR(100),
lokalizacja VARCHAR(100),
nazwa_firmy VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/112/producenci.txt'
INTO TABLE producenci LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

#112.1
/*
SELECT rodzaj, COUNT( distinct mid(ean,1,3)) as ilosc_panstw
FROM towary
GROUP BY rodzaj
*/
#112.2
/*
SELECT nazwa_firmy, lokalizacja
FROM towary
	JOIN kraje ON kraje.kod_kraju = mid(ean,1,3)
	JOIN producenci ON producenci.kod_oddzialu = mid(ean,4,4)
WHERE kraj = 'Czechy'
GROUP BY producenci.kod_oddzialu
ORDER by nazwa_firmy, lokalizacja DESC
*/
#112.3
#WYNIK NIE JEST JEDNOZNACZNY MOIM ZDANIEM
/*
SELECT towary.rodzaj, masa, nazwa
FROM towary,
	(SELECT min(masa) as mmasa, rodzaj
	FROM towary
	GROUP BY rodzaj)x
WHERE towary.rodzaj = x.rodzaj
	AND masa = x.mmasa
GROUP BY towary.rodzaj
*/
#112.4
/*
SELECT nazwa, masa, nazwa_firmy, kraj
FROM towary
	JOIN kraje ON kraje.kod_kraju = mid(ean,1,3)
        JOIN producenci ON producenci.kod_oddzialu = mid(ean,4,4)
WHERE rodzaj LIKE 'baton'
	AND masa > 300
*/
#112.5
#błąd przy Szwajcarii, reszta ok
/*
SELECT kraj, vat, count(*) as liczba_towarow
FROM towary
	JOIN kraje ON kraje.kod_kraju = mid(ean,1,3)
GROUP by kraj, vat
ORDER BY kraj, vat
*/
