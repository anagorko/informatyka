USE matura_sport;

DROP TABLE IF EXISTS osoby;
CREATE TABLE osoby
(
	id_uzytkownika INT,
	nazwisko VARCHAR(100),
	imie VARCHAR(100),
	plec VARCHAR(1)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/101/osoby.txt' INTO TABLE osoby FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS zajecia;
CREATE TABLE zajecia
(
	id_zajec INT,
	obiekt VARCHAR(100),
	zajecia VARCHAR(100),
	koszt INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/101/zajecia.txt' INTO TABLE zajecia FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS wejscia;
CREATE TABLE wejscia
(
	lp INT,
	id_uzytkownika INT,
	data DATE,
	id_zajec INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/101/wejscia.txt' INTO TABLE wejscia FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;



SELECT plec, SUM( wizyty ) as ile
FROM ( SELECT wejscia.id_uzytkownika, plec, COUNT( lp ) as wizyty
	FROM zajecia, wejscia, osoby
	WHERE zajecia.id_zajec = wejscia.id_zajec
		AND wejscia.id_uzytkownika = osoby.id_uzytkownika
		AND zajecia = 'Fitness TBC'
	GROUP BY id_uzytkownika ) as Fitness
GROUP BY plec;


SELECT obiekt, SUM( koszt ) as kwota
FROM zajecia, wejscia
WHERE zajecia.id_zajec = wejscia.id_zajec
GROUP BY obiekt;

SELECT imie, nazwisko
FROM (SELECT imie, nazwisko, COUNT( * ) as ile
	FROM osoby, wejscia
	WHERE osoby.id_uzytkownika = wejscia.id_uzytkownika
		AND data = STR_TO_DATE('16-04-2014', '%d-%m-%Y')
	GROUP BY osoby.id_uzytkownika) as wizyty
WHERE ile > 1;


SELECT zajecia, obiekt
FROM zajecia, (SELECT id_zajec, COUNT( id_uzytkownika ) as ktore
		FROM wejscia
		GROUP BY id_zajec) as popularnosc
WHERE popularnosc.id_zajec = zajecia.id_zajec
ORDER BY popularnosc.ktore DESC	
LIMIT 1;


SELECT obiekt, COUNT( * )
FROM zajecia, wejscia
WHERE zajecia.id_zajec = wejscia.id_zajec
GROUP BY obiekt
ORDER BY obiekt;