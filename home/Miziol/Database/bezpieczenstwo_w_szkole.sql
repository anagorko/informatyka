USE bezpieczenstwo_w_szkole;

DROP TABLE IF EXISTS ankiety;
CREATE TABLE ankiety
(
	nr_ankiety VARCHAR(5),
	pyt1 INT,
	pyt2 INT,
	pyt3 INT,
	pyt4 INT,
	pyt5 INT,
	pyt6 INT,
	id_szkoly VARCHAR(4),
	plec VARCHAR(1)
);
LOAD DATA LOCAL INFILE '../../../zbior_zadan/99/ankiety.txt' INTO TABLE ankiety LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS szkoly;
CREATE TABLE szkoly
(
	id_szkoly VARCHAR(4),
	rodzaj_szkoly VARCHAR(2),
	kod_gminy VARCHAR(4)
);
LOAD DATA LOCAL INFILE '../../../zbior_zadan/99/szkoly.txt' INTO TABLE szkoly LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


DROP TABLE IF EXISTS gminy;
CREATE TABLE gminy
(
	kod_gminy VARCHAR(4),
	nazwa_gminy VARCHAR(100)
);
LOAD DATA LOCAL INFILE '../../../zbior_zadan/99/gminy.txt' INTO TABLE gminy LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

SELECT plec, COUNT( plec ) as ile
FROM ankiety
GROUP BY plec
ORDER BY plec;

SELECT rodzaj_szkoly,
		ROUND( AVG(pyt1), 2) as avg_pyt1,
		ROUND( AVG(pyt2), 2) as avg_pyt2,
		ROUND( AVG(pyt3), 2) as avg_pyt3,
		ROUND( AVG(pyt4), 2) as avg_pyt4,
		ROUND( AVG(pyt5), 2) as avg_pyt5,
		ROUND( AVG(pyt6), 2) as avg_pyt6
FROM ankiety, szkoly
WHERE ankiety.id_szkoly=szkoly.id_szkoly
GROUP BY rodzaj_szkoly
ORDER BY rodzaj_szkoly;

SELECT kod_gminy, ROUND( AVG(pyt6), 2) as avg_pyt6
FROM ankiety, szkoly
WHERE ankiety.id_szkoly=szkoly.id_szkoly
GROUP BY kod_gminy
ORDER BY avg_pyt6 DESC;

SELECT rodzaj_szkoly, COUNT( * )
FROM ankiety, szkoly
WHERE ankiety.id_szkoly=szkoly.id_szkoly AND pyt3=5
GROUP BY rodzaj_szkoly
ORDER BY rodzaj_szkoly;

SELECT nazwa_gminy, SUM( ile_uczniow ) as ile
FROM gminy,
	( SELECT kod_gminy, COUNT( * ) as ile_uczniow
	FROM ankiety, szkoly
	WHERE ankiety.id_szkoly = szkoly.id_szkoly
	GROUP BY ankiety.id_szkoly ) as wyniki
WHERE wyniki.kod_gminy = gminy.kod_gminy
GROUP BY gminy.kod_gminy
ORDER BY ile DESC
LIMIT 1;

SELECT kobiety.rodzaj_szkoly, ile_k, ile_m
FROM ( SELECT rodzaj_szkoly, COUNT( * ) as ile_k
	FROM szkoly, ankiety
	WHERE szkoly.id_szkoly = ankiety.id_szkoly AND plec LIKE 'k' AND pyt1 = 5
	GROUP BY rodzaj_szkoly ) as kobiety,
	( SELECT rodzaj_szkoly, COUNT( * ) as ile_m
	FROM szkoly, ankiety
	WHERE szkoly.id_szkoly = ankiety.id_szkoly AND plec LIKE 'm' AND pyt1 = 5
	GROUP BY rodzaj_szkoly ) as mezczyzni
WHERE mezczyzni.rodzaj_szkoly = kobiety.rodzaj_szkoly
ORDER BY kobiety.rodzaj_szkoly;