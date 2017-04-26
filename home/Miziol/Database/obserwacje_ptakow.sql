USE obserwacje;

DROP TABLE IF EXISTS gatunki;
CREATE TABLE gatunki
(
	id_gatunku int,
	nazwa_zwyczajowa VARCHAR(100),
	nazwa_lacinska VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/106/gatunki.txt' INTO TABLE gatunki LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS lokalizacje;
CREATE TABLE lokalizacje
(
	id_lokalizacji INT,
	lokalizacja VARCHAR(100),
	powiat VARCHAR(100),
	opis VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/106/lokalizacje.txt' INTO TABLE lokalizacje LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS obserwacje;
CREATE TABLE obserwacje
(
	id_gatunku INT,
	id_lokalizacji INT,
	poczatek DATETIME,
	koniec DATETIME,
	liczebnosc INT,
	zachowanie VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/106/obserwacje.txt' INTO TABLE obserwacje LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

SELECT id_gatunku, COUNT( liczebnosc ) as ile
	FROM obserwacje
	GROUP BY id_gatunku
	ORDER BY ile DESC
	LIMIT 3;

SELECT MONTH( poczatek ) as miesiac, SUM( liczebnosc ) as ile_w_miesiacu
	FROM obserwacje, gatunki
	WHERE gatunki.id_gatunku = obserwacje.id_gatunku
	AND nazwa_zwyczajowa LIKE 'remiz'
	GROUP BY miesiac
	ORDER BY miesiac;

SELECT nazwa_lacinska, SUM( liczebnosc ) as ile_zaobserwowano
	FROM gatunki, obserwacje, lokalizacje
	WHERE gatunki.id_gatunku = obserwacje.id_gatunku
	AND obserwacje.id_lokalizacji = lokalizacje.id_lokalizacji
	AND opis LIKE '%miasto%'
	AND nazwa_lacinska LIKE 'Corvus%'
	GROUP BY nazwa_lacinska;

SELECT lokalizacja, DATE( poczatek ) as data, TIMEDIFF ( koniec, poczatek ) as czas, SUM( liczebnosc )
	FROM obserwacje, lokalizacje
	WHERE obserwacje.id_lokalizacji = lokalizacje.id_lokalizacji
	GROUP BY poczatek, koniec, lokalizacja
	ORDER BY czas DESC
	LIMIT 1;

SELECT lokalizacja, DATE( poczatek ) as data, ROUND( SUM( liczebnosc ) / TIMEDIFF ( koniec, poczatek ), 3 ) as sprawnosc
	FROM obserwacje, lokalizacje
	WHERE obserwacje.id_lokalizacji = lokalizacje.id_lokalizacji
	GROUP BY poczatek, koniec, lokalizacja
	ORDER BY sprawnosc DESC
	LIMIT 1;

SELECT nazwa_zwyczajowa, SUM( liczebnosc )
	FROM gatunki, obserwacje
	WHERE gatunki.id_gatunku = obserwacje.id_gatunku
	AND nazwa_zwyczajowa LIKE 'zuraw'
	GROUP BY gatunki.id_gatunku, nazwa_zwyczajowa;