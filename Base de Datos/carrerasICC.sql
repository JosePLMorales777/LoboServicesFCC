/* crear  base de datos */

	drop database if exists CarrerasICC;
	create database CarrerasICC;

/* crear tablas */

	use CarrerasICC;

	CREATE TABLE IF NOT EXISTS Estudiante(
		matricula INT NOT NULL,
		Nombre NVARCHAR(100) NOT NULL,
		contrasena NVARCHAR(45) NOT NULL,
		PRIMARY KEY (matricula));

	CREATE TABLE IF NOT EXISTS Materia(
		idMateria INT NOT NULL,
		Nombre NVARCHAR(100) NOT NULL,
		creditos INT NOT NULL,
		optativaI TINYINT NOT NULL,
		optativaII TINYINT NOT NULL,
		optativaDESIT TINYINT NOT NULL,
		PRIMARY KEY (idMateria));

	CREATE TABLE IF NOT EXISTS InfoMateria(
		matricula INT NOT NULL,
		idMateria INT NOT NULL,
		cursada TINYINT NOT NULL,
		encurso TINYINT NOT NULL,
		disponible TINYINT NOT NULL,
		ninguno TINYINT NOT NULL,
		FOREIGN KEY(matricula) REFERENCES Estudiante(matricula),
		FOREIGN KEY(idMateria) REFERENCES Materia(idMateria),
		PRIMARY KEY(matricula,idMateria));

	CREATE TABLE IF NOT EXISTS Requisito(
		idMateria1 INT NOT NULL,
		idMateria2 INT NOT NULL,
		FOREIGN KEY(idMateria1) REFERENCES Materia(idMateria),
		FOREIGN KEY(idMateria2) REFERENCES Materia(idMateria),
		PRIMARY KEY(idMateria1,idMateria2));

	CREATE TABLE IF NOT EXISTS Maestro(
		matricula INT NOT NULL,
		Nombre NVARCHAR(100) NOT NULL,
		contrasena NVARCHAR(45) NOT NULL,
		PRIMARY KEY (matricula));

