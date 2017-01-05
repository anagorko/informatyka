USE tablice;

DROP TABLE IF EXISTS tablice;

CREATE TABLE tablice(
ozn VARCHAR(100),
powiat VARCHAR(100),
siedziba VARCHAR(100),
rodzaj VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/tablice.txt'
INTO TABLE tablice IGNORE 1 LINES;


DROP TABLE IF EXISTS uslugi;

CREATE TABLE uslugi(
nip VARCHAR(100),
ozn VARCHAR(100),
nr VARCHAR(100),
rodzaj VARCHAR(100),
rata INT
);

LOAD DATA LOCAL INFILE '../../../matura/uslugi.txt'
INTO TABLE uslugi IGNORE 1 LINES;

DROP TABLE IF EXISTS nip_firm;

CREATE TABLE nip_firm(
nip VARCHAR(100),
firma VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/nip_firm.txt'
INTO TABLE nip_firm IGNORE 1 LINES;





#QUERIES

#a)

SELECT SUM(rata) AS leasing
FROM uslugi
WHERE rodzaj ='L';
SELECT SUM(rata) AS wynajem
FROM uslugi
WHERE rodzaj='W';

#b)

SELECT ozn, nr
FROM nip_firm, uslugi
WHERE nip_firm.nip = uslugi.nip
	AND nip_firm.firma LIKE 'BARTEX%'
ORDER BY nr;

#c)

SELECT firma, count(firma) AS ilosc
FROM nip_firm, uslugi
WHERE nip_firm.nip = uslugi.nip
	AND uslugi.rodzaj = 'L'
GROUP BY firma
ORDER BY ilosc DESC
LIMIT 1\G

#d)

SELECT powiat
FROM uslugi, tablice
WHERE uslugi.ozn = tablice.ozn
	AND tablice.rodzaj LIKE 'z%'
GROUP BY powiat;

#e)

SELECT x.firma, (x.suma/x.ilosc) AS 'srednia miesieczna rata'
FROM
	(SELECT firma, sum(rata) AS suma, count(firma) AS ilosc
	FROM uslugi, nip_firm, tablice
	WHERE nip_firm.nip = uslugi.nip
		AND tablice.ozn = uslugi.ozn
		AND tablice.powiat LIKE 'Konin%'
	GROUP BY firma)x\G

