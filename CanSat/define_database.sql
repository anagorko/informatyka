DROP TABLE IF EXISTS data;
CREATE TABLE data
(
	temperature INT,
	preasure INT,
	spectrum BLOB
);

INSERT INTO data VALUES ( 12, 12, X`A4D3F53` );

SELECT * FROM data;