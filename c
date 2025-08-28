--
-- PostgreSQL database cluster dump
--

SET default_transaction_read_only = off;

SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;

--
-- Roles
--

CREATE ROLE gabriel;
ALTER ROLE gabriel WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN NOREPLICATION NOBYPASSRLS PASSWORD 'md5df51a2eeaf9776eeff62d66da993e653';
CREATE ROLE gesta;
ALTER ROLE gesta WITH NOSUPERUSER INHERIT NOCREATEROLE CREATEDB LOGIN NOREPLICATION NOBYPASSRLS PASSWORD 'md51db733ffcf9332b1460b9c74c9d372f2';
CREATE ROLE postgres;
ALTER ROLE postgres WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN REPLICATION BYPASSRLS PASSWORD 'md5560e432c5e857e2ef91dfed204ebde5b';
CREATE ROLE user1;
ALTER ROLE user1 WITH NOSUPERUSER INHERIT NOCREATEROLE CREATEDB LOGIN REPLICATION NOBYPASSRLS PASSWORD 'md581d02a11e34d844c3b1db6a484e95fac';






--
-- Databases
--

--
-- Database "template1" dump
--

\connect template1

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "EducationCity" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: EducationCity; Type: DATABASE; Schema: -; Owner: gesta
--

CREATE DATABASE "EducationCity" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE "EducationCity" OWNER TO gesta;

\connect "EducationCity"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "bevan" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: bevan; Type: DATABASE; Schema: -; Owner: gabriel
--

CREATE DATABASE bevan WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE bevan OWNER TO gabriel;

\connect bevan

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "client" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: client; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE client WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE client OWNER TO postgres;

\connect client

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: clients; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.clients (
    id integer NOT NULL,
    nom character varying(40),
    prenom character varying(40),
    age integer,
    adresse character varying(40),
    ville text
);


ALTER TABLE public.clients OWNER TO postgres;

--
-- Name: commande; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.commande (
    idcom integer NOT NULL,
    quantite integer,
    id integer
);


ALTER TABLE public.commande OWNER TO postgres;

--
-- Data for Name: clients; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.clients (id, nom, prenom, age, adresse, ville) FROM stdin;
1	kamisy	Almiron	15	Tanamakoa	Toamasina
2	Rabe	Fabien	56	Ampasimazava	Toamasina
3	Doda	billy	23	Andohalo	Antananarivo
4	Guy	Dimby	23	Ankadifotsy	Antananarivo
14	jacque	daniel	22	67 ha	Antananarivo
15	didier	drogba	56	vohitsara	toamasina
16	xavier	xavier	56	vohitsara	toamasina
17	Gabriel	Andria	27	Mahavanona	Toamasina 2
\.


--
-- Data for Name: commande; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.commande (idcom, quantite, id) FROM stdin;
1	2	4
2	5	14
\.


--
-- Name: clients clients_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (id);


--
-- Name: commande commande_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_pkey PRIMARY KEY (idcom);


--
-- PostgreSQL database dump complete
--

--
-- Database "dbAssurance" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: dbAssurance; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "dbAssurance" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE "dbAssurance" OWNER TO postgres;

\connect "dbAssurance"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "dbGesta" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: dbGesta; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "dbGesta" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE "dbGesta" OWNER TO postgres;

\connect "dbGesta"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: test; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.test (
    id integer NOT NULL,
    nom character varying(30) NOT NULL,
    age integer,
    ville character varying(30) DEFAULT 'Toamasina'::character varying,
    numero integer
);


ALTER TABLE public.test OWNER TO postgres;

--
-- Data for Name: test; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.test (id, nom, age, ville, numero) FROM stdin;
\.


--
-- Name: test test_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.test
    ADD CONSTRAINT test_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

--
-- Database "db_ahlem" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_ahlem; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_ahlem WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_ahlem OWNER TO postgres;

\connect db_ahlem

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: administrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.administrations (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    prenom character varying(255) NOT NULL,
    contact character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    adresse character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.administrations OWNER TO postgres;

--
-- Name: administrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.administrations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.administrations_id_seq OWNER TO postgres;

--
-- Name: administrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.administrations_id_seq OWNED BY public.administrations.id;


--
-- Name: chauffeurs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.chauffeurs (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    contact character varying(255) NOT NULL,
    disponibilite character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.chauffeurs OWNER TO postgres;

--
-- Name: chauffeurs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.chauffeurs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.chauffeurs_id_seq OWNER TO postgres;

--
-- Name: chauffeurs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.chauffeurs_id_seq OWNED BY public.chauffeurs.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    expires_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: reservation_administration; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservation_administration (
    reservation_id bigint NOT NULL,
    administration_id bigint NOT NULL
);


ALTER TABLE public.reservation_administration OWNER TO postgres;

--
-- Name: reservation_passager; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservation_passager (
    id bigint NOT NULL,
    reservation_id bigint NOT NULL,
    administration_id bigint NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.reservation_passager OWNER TO postgres;

--
-- Name: reservation_passager_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reservation_passager_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reservation_passager_id_seq OWNER TO postgres;

--
-- Name: reservation_passager_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reservation_passager_id_seq OWNED BY public.reservation_passager.id;


--
-- Name: reservations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservations (
    id bigint NOT NULL,
    date date NOT NULL,
    statut character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    trajet_id bigint,
    vehicule_id bigint,
    chauffeur_id bigint
);


ALTER TABLE public.reservations OWNER TO postgres;

--
-- Name: reservations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reservations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reservations_id_seq OWNER TO postgres;

--
-- Name: reservations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reservations_id_seq OWNED BY public.reservations.id;


--
-- Name: trajets; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.trajets (
    id bigint NOT NULL,
    depart date NOT NULL,
    destination character varying(255) NOT NULL,
    duree_estimee time(0) without time zone NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.trajets OWNER TO postgres;

--
-- Name: trajets_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.trajets_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.trajets_id_seq OWNER TO postgres;

--
-- Name: trajets_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.trajets_id_seq OWNED BY public.trajets.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: vehicules; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.vehicules (
    id bigint NOT NULL,
    immatriculation character varying(255) NOT NULL,
    marque character varying(255) NOT NULL,
    modele character varying(255) NOT NULL,
    statut character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.vehicules OWNER TO postgres;

--
-- Name: vehicules_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.vehicules_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.vehicules_id_seq OWNER TO postgres;

--
-- Name: vehicules_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.vehicules_id_seq OWNED BY public.vehicules.id;


--
-- Name: administrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.administrations ALTER COLUMN id SET DEFAULT nextval('public.administrations_id_seq'::regclass);


--
-- Name: chauffeurs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chauffeurs ALTER COLUMN id SET DEFAULT nextval('public.chauffeurs_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: reservation_passager id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager ALTER COLUMN id SET DEFAULT nextval('public.reservation_passager_id_seq'::regclass);


--
-- Name: reservations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations ALTER COLUMN id SET DEFAULT nextval('public.reservations_id_seq'::regclass);


--
-- Name: trajets id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.trajets ALTER COLUMN id SET DEFAULT nextval('public.trajets_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Name: vehicules id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicules ALTER COLUMN id SET DEFAULT nextval('public.vehicules_id_seq'::regclass);


--
-- Data for Name: administrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.administrations (id, nom, prenom, contact, email, adresse, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: chauffeurs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.chauffeurs (id, nom, contact, disponibilite, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	2014_10_12_000000_create_users_table	1
2	2014_10_12_100000_create_password_reset_tokens_table	1
3	2019_08_19_000000_create_failed_jobs_table	1
4	2019_12_14_000001_create_personal_access_tokens_table	1
5	2025_06_20_054539_create_vehicules_table	1
6	2025_06_20_054555_create_reservations_table	1
7	2025_06_20_054614_create_chauffeurs_table	1
8	2025_06_20_054627_create_trajets_table	1
9	2025_06_20_054641_create_administrations_table	1
10	2025_06_20_070723_add_trajet_id_to_reservation	1
11	2025_06_20_070744_add_vehicule_id_to_reservation	1
12	2025_06_20_070806_add_chauffeur_id_to_reservation	1
13	2025_06_20_072200_reservation-passager	1
14	2025_07_10_031650_create_reservation_administration_table	1
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, expires_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: reservation_administration; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservation_administration (reservation_id, administration_id) FROM stdin;
\.


--
-- Data for Name: reservation_passager; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservation_passager (id, reservation_id, administration_id, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: reservations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservations (id, date, statut, created_at, updated_at, trajet_id, vehicule_id, chauffeur_id) FROM stdin;
\.


--
-- Data for Name: trajets; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.trajets (id, depart, destination, duree_estimee, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: vehicules; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.vehicules (id, immatriculation, marque, modele, statut, created_at, updated_at) FROM stdin;
\.


--
-- Name: administrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.administrations_id_seq', 1, false);


--
-- Name: chauffeurs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.chauffeurs_id_seq', 1, false);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 14, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: reservation_passager_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reservation_passager_id_seq', 1, false);


--
-- Name: reservations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reservations_id_seq', 1, false);


--
-- Name: trajets_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.trajets_id_seq', 1, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: vehicules_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.vehicules_id_seq', 1, true);


--
-- Name: administrations administrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.administrations
    ADD CONSTRAINT administrations_pkey PRIMARY KEY (id);


--
-- Name: chauffeurs chauffeurs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chauffeurs
    ADD CONSTRAINT chauffeurs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: reservation_passager reservation_passager_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager
    ADD CONSTRAINT reservation_passager_pkey PRIMARY KEY (id);


--
-- Name: reservations reservations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_pkey PRIMARY KEY (id);


--
-- Name: trajets trajets_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.trajets
    ADD CONSTRAINT trajets_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: vehicules vehicules_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicules
    ADD CONSTRAINT vehicules_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- Name: reservation_administration reservation_administration_administration_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_administration
    ADD CONSTRAINT reservation_administration_administration_id_foreign FOREIGN KEY (administration_id) REFERENCES public.administrations(id) ON DELETE CASCADE;


--
-- Name: reservation_administration reservation_administration_reservation_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_administration
    ADD CONSTRAINT reservation_administration_reservation_id_foreign FOREIGN KEY (reservation_id) REFERENCES public.reservations(id) ON DELETE CASCADE;


--
-- Name: reservation_passager reservation_passager_administration_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager
    ADD CONSTRAINT reservation_passager_administration_id_foreign FOREIGN KEY (administration_id) REFERENCES public.administrations(id) ON DELETE CASCADE;


--
-- Name: reservation_passager reservation_passager_reservation_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager
    ADD CONSTRAINT reservation_passager_reservation_id_foreign FOREIGN KEY (reservation_id) REFERENCES public.reservations(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_chauffeur_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_chauffeur_id_foreign FOREIGN KEY (chauffeur_id) REFERENCES public.chauffeurs(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_trajet_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_trajet_id_foreign FOREIGN KEY (trajet_id) REFERENCES public.trajets(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_vehicule_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_vehicule_id_foreign FOREIGN KEY (vehicule_id) REFERENCES public.vehicules(id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

--
-- Database "db_alpha" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_alpha; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_alpha WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_alpha OWNER TO postgres;

\connect db_alpha

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: chauffeurs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.chauffeurs (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    contact character varying(255) NOT NULL,
    disponibilite character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.chauffeurs OWNER TO postgres;

--
-- Name: chauffeurs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.chauffeurs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.chauffeurs_id_seq OWNER TO postgres;

--
-- Name: chauffeurs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.chauffeurs_id_seq OWNED BY public.chauffeurs.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: passagers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.passagers (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    prenom character varying(255) NOT NULL,
    contact character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    adresse character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.passagers OWNER TO postgres;

--
-- Name: passagers_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.passagers_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.passagers_id_seq OWNER TO postgres;

--
-- Name: passagers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.passagers_id_seq OWNED BY public.passagers.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    expires_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: reservation_passagers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservation_passagers (
    id bigint NOT NULL,
    reservation_id bigint,
    passager_id bigint,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.reservation_passagers OWNER TO postgres;

--
-- Name: reservation_passagers_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reservation_passagers_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reservation_passagers_id_seq OWNER TO postgres;

--
-- Name: reservation_passagers_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reservation_passagers_id_seq OWNED BY public.reservation_passagers.id;


--
-- Name: reservations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservations (
    id bigint NOT NULL,
    date_reservation date NOT NULL,
    statut character varying(255) NOT NULL,
    trajet_id bigint,
    vehicule_id bigint,
    chauffeur_id bigint,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.reservations OWNER TO postgres;

--
-- Name: reservations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reservations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reservations_id_seq OWNER TO postgres;

--
-- Name: reservations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reservations_id_seq OWNED BY public.reservations.id;


--
-- Name: trajets; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.trajets (
    id bigint NOT NULL,
    depart character varying(255) NOT NULL,
    destination character varying(255) NOT NULL,
    duree_estimee character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.trajets OWNER TO postgres;

--
-- Name: trajets_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.trajets_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.trajets_id_seq OWNER TO postgres;

--
-- Name: trajets_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.trajets_id_seq OWNED BY public.trajets.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: vehicules; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.vehicules (
    id bigint NOT NULL,
    immatriculation character varying(255) NOT NULL,
    marque character varying(255) NOT NULL,
    modele character varying(255) NOT NULL,
    statut character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.vehicules OWNER TO postgres;

--
-- Name: vehicules_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.vehicules_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.vehicules_id_seq OWNER TO postgres;

--
-- Name: vehicules_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.vehicules_id_seq OWNED BY public.vehicules.id;


--
-- Name: chauffeurs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chauffeurs ALTER COLUMN id SET DEFAULT nextval('public.chauffeurs_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: passagers id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.passagers ALTER COLUMN id SET DEFAULT nextval('public.passagers_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: reservation_passagers id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passagers ALTER COLUMN id SET DEFAULT nextval('public.reservation_passagers_id_seq'::regclass);


--
-- Name: reservations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations ALTER COLUMN id SET DEFAULT nextval('public.reservations_id_seq'::regclass);


--
-- Name: trajets id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.trajets ALTER COLUMN id SET DEFAULT nextval('public.trajets_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Name: vehicules id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicules ALTER COLUMN id SET DEFAULT nextval('public.vehicules_id_seq'::regclass);


--
-- Data for Name: chauffeurs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.chauffeurs (id, nom, contact, disponibilite, created_at, updated_at) FROM stdin;
1	Charlotte Marquardt	+1.240.202.1751	1	2025-06-24 08:49:08	2025-06-24 08:49:08
2	Dr. Major Oberbrunner	915-866-8870	0	2025-06-24 08:49:08	2025-06-24 08:49:08
3	Lyda Kub	+1-973-966-6720	0	2025-06-24 08:49:08	2025-06-24 08:49:08
4	Corrine Bogan	+1-505-309-6713	0	2025-06-24 08:49:08	2025-06-24 08:49:08
5	Zora Dach	240-429-8387	1	2025-06-24 08:49:08	2025-06-24 08:49:08
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
11	2014_10_12_000000_create_users_table	1
12	2014_10_12_100000_create_password_reset_tokens_table	1
13	2019_08_19_000000_create_failed_jobs_table	1
14	2019_12_14_000001_create_personal_access_tokens_table	1
15	2025_06_20_035109_create_passagers_table	1
16	2025_06_20_035158_create_vehicules_table	1
17	2025_06_20_035212_create_chauffeurs_table	1
18	2025_06_20_035222_create_trajets_table	1
19	2025_06_20_054729_create_reservations_table	1
20	2025_06_20_054745_create_reservation_passagers_table	1
\.


--
-- Data for Name: passagers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.passagers (id, nom, prenom, contact, email, adresse, created_at, updated_at) FROM stdin;
1	Arno Huels	Schuster	+1-734-857-8760	obruen@example.com	56594 Mosciski Drive Apt. 738\nStammborough, AZ 41717	2025-06-24 08:49:08	2025-06-24 08:49:08
2	Jermaine Botsford	Crist	(618) 397-5938	jhermiston@example.com	8779 Lucile Stravenue Apt. 641\nWest Elena, AZ 74989-2273	2025-06-24 08:49:08	2025-06-24 08:49:08
3	Bonnie Nitzsche	Witting	+1-850-718-3446	paufderhar@example.com	51930 Abbott Lake\nSouth Dejuanfurt, OH 70314-4639	2025-06-24 08:49:08	2025-06-24 08:49:08
4	Tia Conroy	Schmeler	+1-708-659-3350	lhauck@example.net	328 Carmella Wells Suite 835\nPort Hestertown, AL 16243-1999	2025-06-24 08:49:08	2025-06-24 08:49:08
5	Tamara Moen	Anderson	669.383.0770	quitzon.suzanne@example.com	4388 Mante Track Suite 907\nGloverfort, IL 31055-0897	2025-06-24 08:49:08	2025-06-24 08:49:08
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, expires_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: reservation_passagers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservation_passagers (id, reservation_id, passager_id, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: reservations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservations (id, date_reservation, statut, trajet_id, vehicule_id, chauffeur_id, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: trajets; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.trajets (id, depart, destination, duree_estimee, created_at, updated_at) FROM stdin;
1	Port Sophia	Tiffanyfort	97	2025-06-24 08:49:08	2025-06-24 08:49:08
2	Johnsside	South Triston	54	2025-06-24 08:49:08	2025-06-24 08:49:08
3	Faheyville	Myafurt	170	2025-06-24 08:49:08	2025-06-24 08:49:08
4	West Vida	Shaniamouth	128	2025-06-24 08:49:08	2025-06-24 08:49:08
5	Port Addie	North Gaetano	95	2025-06-24 08:49:08	2025-06-24 08:49:08
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: vehicules; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.vehicules (id, immatriculation, marque, modele, statut, created_at, updated_at) FROM stdin;
1	at-8477	Honda	dolorum	réservé	2025-06-24 08:49:08	2025-06-24 08:49:08
2	ch-6947	Honda	officia	réservé	2025-06-24 08:49:08	2025-06-24 08:49:08
3	yv-3784	Nissan	sed	disponible	2025-06-24 08:49:08	2025-06-24 08:49:08
4	md-9609	Chevrolet	ad	en maintenance	2025-06-24 08:49:08	2025-06-24 08:49:08
5	nq-9508	Chevrolet	sequi	réservé	2025-06-24 08:49:08	2025-06-24 08:49:08
\.


--
-- Name: chauffeurs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.chauffeurs_id_seq', 5, true);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 20, true);


--
-- Name: passagers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.passagers_id_seq', 5, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: reservation_passagers_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reservation_passagers_id_seq', 1, false);


--
-- Name: reservations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reservations_id_seq', 1, false);


--
-- Name: trajets_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.trajets_id_seq', 5, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: vehicules_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.vehicules_id_seq', 5, true);


--
-- Name: chauffeurs chauffeurs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chauffeurs
    ADD CONSTRAINT chauffeurs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: passagers passagers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.passagers
    ADD CONSTRAINT passagers_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: reservation_passagers reservation_passagers_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passagers
    ADD CONSTRAINT reservation_passagers_pkey PRIMARY KEY (id);


--
-- Name: reservations reservations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_pkey PRIMARY KEY (id);


--
-- Name: trajets trajets_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.trajets
    ADD CONSTRAINT trajets_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: vehicules vehicules_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicules
    ADD CONSTRAINT vehicules_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- Name: reservation_passagers reservation_passagers_passager_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passagers
    ADD CONSTRAINT reservation_passagers_passager_id_foreign FOREIGN KEY (passager_id) REFERENCES public.passagers(id) ON DELETE CASCADE;


--
-- Name: reservation_passagers reservation_passagers_reservation_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passagers
    ADD CONSTRAINT reservation_passagers_reservation_id_foreign FOREIGN KEY (reservation_id) REFERENCES public.reservations(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_chauffeur_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_chauffeur_id_foreign FOREIGN KEY (chauffeur_id) REFERENCES public.chauffeurs(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_trajet_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_trajet_id_foreign FOREIGN KEY (trajet_id) REFERENCES public.trajets(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_vehicule_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_vehicule_id_foreign FOREIGN KEY (vehicule_id) REFERENCES public.vehicules(id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

--
-- Database "db_freddy" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_freddy; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_freddy WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_freddy OWNER TO postgres;

\connect db_freddy

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: admninistrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.admninistrations (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    prenom character varying(255) NOT NULL,
    contact character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    adresse character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.admninistrations OWNER TO postgres;

--
-- Name: admninistrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.admninistrations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.admninistrations_id_seq OWNER TO postgres;

--
-- Name: admninistrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.admninistrations_id_seq OWNED BY public.admninistrations.id;


--
-- Name: chauffeurs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.chauffeurs (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    contact character varying(255) NOT NULL,
    disponibilite character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.chauffeurs OWNER TO postgres;

--
-- Name: chauffeurs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.chauffeurs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.chauffeurs_id_seq OWNER TO postgres;

--
-- Name: chauffeurs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.chauffeurs_id_seq OWNED BY public.chauffeurs.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    expires_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: reservation_passager; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservation_passager (
    id bigint NOT NULL,
    reservation_id bigint NOT NULL,
    administration_id bigint NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.reservation_passager OWNER TO postgres;

--
-- Name: reservation_passager_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reservation_passager_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reservation_passager_id_seq OWNER TO postgres;

--
-- Name: reservation_passager_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reservation_passager_id_seq OWNED BY public.reservation_passager.id;


--
-- Name: reservations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservations (
    id bigint NOT NULL,
    date date NOT NULL,
    statut character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    trajet_id bigint,
    vehicule_id bigint,
    chauffeur_id bigint
);


ALTER TABLE public.reservations OWNER TO postgres;

--
-- Name: reservations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reservations_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reservations_id_seq OWNER TO postgres;

--
-- Name: reservations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reservations_id_seq OWNED BY public.reservations.id;


--
-- Name: trajets; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.trajets (
    id bigint NOT NULL,
    depart date NOT NULL,
    destination character varying(255) NOT NULL,
    duree_estimee time(0) without time zone NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.trajets OWNER TO postgres;

--
-- Name: trajets_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.trajets_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.trajets_id_seq OWNER TO postgres;

--
-- Name: trajets_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.trajets_id_seq OWNED BY public.trajets.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: vehicules; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.vehicules (
    id bigint NOT NULL,
    immatriculation character varying(255) NOT NULL,
    marque character varying(255) NOT NULL,
    modele character varying(255) NOT NULL,
    statut character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.vehicules OWNER TO postgres;

--
-- Name: vehicules_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.vehicules_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.vehicules_id_seq OWNER TO postgres;

--
-- Name: vehicules_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.vehicules_id_seq OWNED BY public.vehicules.id;


--
-- Name: admninistrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.admninistrations ALTER COLUMN id SET DEFAULT nextval('public.admninistrations_id_seq'::regclass);


--
-- Name: chauffeurs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chauffeurs ALTER COLUMN id SET DEFAULT nextval('public.chauffeurs_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: reservation_passager id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager ALTER COLUMN id SET DEFAULT nextval('public.reservation_passager_id_seq'::regclass);


--
-- Name: reservations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations ALTER COLUMN id SET DEFAULT nextval('public.reservations_id_seq'::regclass);


--
-- Name: trajets id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.trajets ALTER COLUMN id SET DEFAULT nextval('public.trajets_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Name: vehicules id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicules ALTER COLUMN id SET DEFAULT nextval('public.vehicules_id_seq'::regclass);


--
-- Data for Name: admninistrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.admninistrations (id, nom, prenom, contact, email, adresse, created_at, updated_at) FROM stdin;
1	Schamberger	Jamey	+1-669-577-0520	dankunding@example.com	9785 Renner Locks Apt. 696\nProsaccofurt, MA 53157	2025-06-24 08:26:26	2025-06-24 08:26:26
2	Welch	Rosalee	+1.424.657.9686	eric87@example.net	7916 Annamarie Mount\nPort Eldonport, CT 18350-4895	2025-06-24 08:26:26	2025-06-24 08:26:26
3	Morar	Jermaine	+1-903-355-4901	osinski.mary@example.com	87104 Pablo Way Suite 749\nSouth Freda, MO 83020	2025-06-24 08:26:26	2025-06-24 08:26:26
4	Gulgowski	Easton	+17543323812	letha.wiegand@example.net	1831 Ullrich Crossroad\nNew Destin, WI 86152	2025-06-24 08:26:26	2025-06-24 08:26:26
5	Strosin	Ahmed	+12137968659	blockman@example.com	174 Schroeder Motorway\nSouth Cydneymouth, MA 61500-5825	2025-06-24 08:26:26	2025-06-24 08:26:26
\.


--
-- Data for Name: chauffeurs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.chauffeurs (id, nom, contact, disponibilite, created_at, updated_at) FROM stdin;
1	Treutel	1-337-603-6955	ea	2025-06-24 08:26:26	2025-06-24 08:26:26
2	Mosciski	+1-507-962-0583	corporis	2025-06-24 08:26:26	2025-06-24 08:26:26
3	Collier	325-872-9007	velit	2025-06-24 08:26:26	2025-06-24 08:26:26
4	Conroy	+1-970-546-8983	voluptas	2025-06-24 08:26:26	2025-06-24 08:26:26
5	Runolfsson	(531) 458-7461	aliquam	2025-06-24 08:26:26	2025-06-24 08:26:26
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	2014_10_12_000000_create_users_table	1
2	2014_10_12_100000_create_password_reset_tokens_table	1
3	2019_08_19_000000_create_failed_jobs_table	1
4	2019_12_14_000001_create_personal_access_tokens_table	1
5	2025_06_20_054440_create_vehicules_table	1
6	2025_06_20_054543_create_reservations_table	1
7	2025_06_20_054556_create_chauffeurs_table	1
8	2025_06_20_054612_create_trajets_table	1
9	2025_06_20_054629_create_admninistrations_table	1
10	2025_06_20_070654_add_trajet_id_to_reservations	1
11	2025_06_20_070737_add_vehicule_id_to_reservations	1
12	2025_06_20_070802_add_chauffeur_id_to_reservations	1
13	2025_06_20_072156_reservation_passager	1
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, expires_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: reservation_passager; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservation_passager (id, reservation_id, administration_id, created_at, updated_at) FROM stdin;
1	1	5	\N	\N
2	2	4	\N	\N
3	3	1	\N	\N
4	3	2	\N	\N
5	3	4	\N	\N
6	4	1	\N	\N
7	4	4	\N	\N
8	5	1	\N	\N
\.


--
-- Data for Name: reservations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservations (id, date, statut, created_at, updated_at, trajet_id, vehicule_id, chauffeur_id) FROM stdin;
1	1971-04-26	eos	2025-06-24 08:26:26	2025-06-24 08:26:26	3	5	5
2	1988-02-26	quibusdam	2025-06-24 08:26:26	2025-06-24 08:26:27	4	5	2
3	1981-06-12	id	2025-06-24 08:26:26	2025-06-24 08:26:27	3	4	5
4	1973-11-17	saepe	2025-06-24 08:26:26	2025-06-24 08:26:27	5	1	2
5	1988-11-08	dicta	2025-06-24 08:26:26	2025-06-24 08:26:27	1	2	2
\.


--
-- Data for Name: trajets; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.trajets (id, depart, destination, duree_estimee, created_at, updated_at) FROM stdin;
1	1994-07-04	Enochland	11:21:26	2025-06-24 08:26:26	2025-06-24 08:26:26
2	2015-06-13	Dooleyhaven	12:40:06	2025-06-24 08:26:26	2025-06-24 08:26:26
3	1986-08-14	New Shawnmouth	23:41:27	2025-06-24 08:26:26	2025-06-24 08:26:26
4	1983-03-09	Imogeneburgh	17:35:46	2025-06-24 08:26:26	2025-06-24 08:26:26
5	2006-02-06	Port Camryn	14:37:01	2025-06-24 08:26:26	2025-06-24 08:26:26
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: vehicules; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.vehicules (id, immatriculation, marque, modele, statut, created_at, updated_at) FROM stdin;
1	distinctio	ullam	cumque	Disponible	2025-06-24 08:26:26	2025-06-24 08:26:26
2	ipsa	sequi	accusantium	Indisponible	2025-06-24 08:26:26	2025-06-24 08:26:26
3	dolorum	qui	quia	Disponible	2025-06-24 08:26:26	2025-06-24 08:26:26
4	porro	non	aut	En maintenance	2025-06-24 08:26:26	2025-06-24 08:26:26
5	doloremque	soluta	aut	Indisponible	2025-06-24 08:26:26	2025-06-24 08:26:26
\.


--
-- Name: admninistrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.admninistrations_id_seq', 5, true);


--
-- Name: chauffeurs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.chauffeurs_id_seq', 5, true);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 13, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: reservation_passager_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reservation_passager_id_seq', 8, true);


--
-- Name: reservations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reservations_id_seq', 5, true);


--
-- Name: trajets_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.trajets_id_seq', 5, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: vehicules_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.vehicules_id_seq', 5, true);


--
-- Name: admninistrations admninistrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.admninistrations
    ADD CONSTRAINT admninistrations_pkey PRIMARY KEY (id);


--
-- Name: chauffeurs chauffeurs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chauffeurs
    ADD CONSTRAINT chauffeurs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: reservation_passager reservation_passager_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager
    ADD CONSTRAINT reservation_passager_pkey PRIMARY KEY (id);


--
-- Name: reservations reservations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_pkey PRIMARY KEY (id);


--
-- Name: trajets trajets_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.trajets
    ADD CONSTRAINT trajets_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: vehicules vehicules_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.vehicules
    ADD CONSTRAINT vehicules_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- Name: reservation_passager reservation_passager_administration_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager
    ADD CONSTRAINT reservation_passager_administration_id_foreign FOREIGN KEY (administration_id) REFERENCES public.admninistrations(id) ON DELETE CASCADE;


--
-- Name: reservation_passager reservation_passager_reservation_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation_passager
    ADD CONSTRAINT reservation_passager_reservation_id_foreign FOREIGN KEY (reservation_id) REFERENCES public.reservations(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_chauffeur_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_chauffeur_id_foreign FOREIGN KEY (chauffeur_id) REFERENCES public.chauffeurs(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_trajet_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_trajet_id_foreign FOREIGN KEY (trajet_id) REFERENCES public.trajets(id) ON DELETE CASCADE;


--
-- Name: reservations reservations_vehicule_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservations
    ADD CONSTRAINT reservations_vehicule_id_foreign FOREIGN KEY (vehicule_id) REFERENCES public.vehicules(id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

--
-- Database "db_hardy" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_hardy; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_hardy WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_hardy OWNER TO postgres;

\connect db_hardy

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "db_nael" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_nael; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_nael WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_nael OWNER TO postgres;

\connect db_nael

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "db_societe" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_societe; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_societe WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_societe OWNER TO postgres;

\connect db_societe

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: fournisseur; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.fournisseur (
    numf integer NOT NULL,
    nomf character varying(255) NOT NULL,
    villef character varying(255) NOT NULL,
    statut character varying(50)
);


ALTER TABLE public.fournisseur OWNER TO postgres;

--
-- Name: fournisseur_numf_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.fournisseur_numf_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.fournisseur_numf_seq OWNER TO postgres;

--
-- Name: fournisseur_numf_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.fournisseur_numf_seq OWNED BY public.fournisseur.numf;


--
-- Name: livraison; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.livraison (
    numu integer NOT NULL,
    nump integer NOT NULL,
    numf integer NOT NULL,
    "quantité" integer NOT NULL
);


ALTER TABLE public.livraison OWNER TO postgres;

--
-- Name: produit; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produit (
    nump integer NOT NULL,
    nomp character varying(255) NOT NULL,
    couleur character varying(50),
    poids numeric(10,2)
);


ALTER TABLE public.produit OWNER TO postgres;

--
-- Name: produit_nump_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.produit_nump_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.produit_nump_seq OWNER TO postgres;

--
-- Name: produit_nump_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.produit_nump_seq OWNED BY public.produit.nump;


--
-- Name: usine; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.usine (
    numu integer NOT NULL,
    nomu character varying(255) NOT NULL,
    villeu character varying(255) NOT NULL
);


ALTER TABLE public.usine OWNER TO postgres;

--
-- Name: usine_numu_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.usine_numu_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.usine_numu_seq OWNER TO postgres;

--
-- Name: usine_numu_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.usine_numu_seq OWNED BY public.usine.numu;


--
-- Name: fournisseur numf; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fournisseur ALTER COLUMN numf SET DEFAULT nextval('public.fournisseur_numf_seq'::regclass);


--
-- Name: produit nump; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produit ALTER COLUMN nump SET DEFAULT nextval('public.produit_nump_seq'::regclass);


--
-- Name: usine numu; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usine ALTER COLUMN numu SET DEFAULT nextval('public.usine_numu_seq'::regclass);


--
-- Data for Name: fournisseur; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.fournisseur (numf, nomf, villef, statut) FROM stdin;
1	Fournisseur A	Paris	sous-traitant
2	Fournisseur B	Lyon	client
3	Fournisseur C	Marseille	fournisseur
4	Fournisseur D	Paris	sous-traitant
\.


--
-- Data for Name: livraison; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.livraison (numu, nump, numf, "quantité") FROM stdin;
1	1	1	30
1	2	2	50
2	3	3	120
3	4	4	200
2	1	1	10
3	2	3	60
4	3	4	90
\.


--
-- Data for Name: produit; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produit (nump, nomp, couleur, poids) FROM stdin;
1	Produit X	rouge	5.00
2	Produit Y	bleu	10.00
3	Produit Z	rouge	3.00
4	Produit W	vert	7.00
\.


--
-- Data for Name: usine; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.usine (numu, nomu, villeu) FROM stdin;
1	Usine A	Paris
2	Usine B	Lyon
3	Usine C	Paris
4	Usine D	Marseille
\.


--
-- Name: fournisseur_numf_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.fournisseur_numf_seq', 1, false);


--
-- Name: produit_nump_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.produit_nump_seq', 1, false);


--
-- Name: usine_numu_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.usine_numu_seq', 1, false);


--
-- Name: fournisseur fournisseur_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fournisseur
    ADD CONSTRAINT fournisseur_pkey PRIMARY KEY (numf);


--
-- Name: livraison livraison_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_pkey PRIMARY KEY (numu, nump, numf);


--
-- Name: produit produit_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produit
    ADD CONSTRAINT produit_pkey PRIMARY KEY (nump);


--
-- Name: usine usine_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usine
    ADD CONSTRAINT usine_pkey PRIMARY KEY (numu);


--
-- Name: livraison livraison_numf_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_numf_fkey FOREIGN KEY (numf) REFERENCES public.fournisseur(numf) ON DELETE CASCADE;


--
-- Name: livraison livraison_nump_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_nump_fkey FOREIGN KEY (nump) REFERENCES public.produit(nump) ON DELETE CASCADE;


--
-- Name: livraison livraison_numu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_numu_fkey FOREIGN KEY (numu) REFERENCES public.usine(numu) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

--
-- Database "db_stocks" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: db_stocks; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE db_stocks WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE db_stocks OWNER TO postgres;

\connect db_stocks

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: cache; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cache (
    key character varying(255) NOT NULL,
    value text NOT NULL,
    expiration integer NOT NULL
);


ALTER TABLE public.cache OWNER TO postgres;

--
-- Name: cache_locks; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cache_locks (
    key character varying(255) NOT NULL,
    owner character varying(255) NOT NULL,
    expiration integer NOT NULL
);


ALTER TABLE public.cache_locks OWNER TO postgres;

--
-- Name: categories; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.categories (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    description text,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    reference character varying(255) NOT NULL
);


ALTER TABLE public.categories OWNER TO postgres;

--
-- Name: categories_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.categories_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.categories_id_seq OWNER TO postgres;

--
-- Name: categories_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.categories_id_seq OWNED BY public.categories.id;


--
-- Name: entrepots; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.entrepots (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    emplacement character varying(255),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.entrepots OWNER TO postgres;

--
-- Name: entrepots_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.entrepots_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.entrepots_id_seq OWNER TO postgres;

--
-- Name: entrepots_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.entrepots_id_seq OWNED BY public.entrepots.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: fournisseurs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.fournisseurs (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    email character varying(255),
    telephone character varying(255),
    adresse text,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    statut character varying(255) DEFAULT 'en attente'::character varying NOT NULL,
    CONSTRAINT fournisseurs_statut_check CHECK (((statut)::text = ANY ((ARRAY['actif'::character varying, 'inactif'::character varying, 'blacklisté'::character varying, 'en attente'::character varying])::text[])))
);


ALTER TABLE public.fournisseurs OWNER TO postgres;

--
-- Name: fournisseurs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.fournisseurs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.fournisseurs_id_seq OWNER TO postgres;

--
-- Name: fournisseurs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.fournisseurs_id_seq OWNED BY public.fournisseurs.id;


--
-- Name: job_batches; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.job_batches (
    id character varying(255) NOT NULL,
    name character varying(255) NOT NULL,
    total_jobs integer NOT NULL,
    pending_jobs integer NOT NULL,
    failed_jobs integer NOT NULL,
    failed_job_ids text NOT NULL,
    options text,
    cancelled_at integer,
    created_at integer NOT NULL,
    finished_at integer
);


ALTER TABLE public.job_batches OWNER TO postgres;

--
-- Name: jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.jobs (
    id bigint NOT NULL,
    queue character varying(255) NOT NULL,
    payload text NOT NULL,
    attempts smallint NOT NULL,
    reserved_at integer,
    available_at integer NOT NULL,
    created_at integer NOT NULL
);


ALTER TABLE public.jobs OWNER TO postgres;

--
-- Name: jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.jobs_id_seq OWNER TO postgres;

--
-- Name: jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.jobs_id_seq OWNED BY public.jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: produits; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produits (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    description text,
    prix_unitaire numeric(10,2) NOT NULL,
    categorie_id bigint,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    code_produit character varying(255) NOT NULL,
    prix_achat numeric(10,2),
    unite_mesure_id bigint
);


ALTER TABLE public.produits OWNER TO postgres;

--
-- Name: produits_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.produits_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.produits_id_seq OWNER TO postgres;

--
-- Name: produits_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.produits_id_seq OWNED BY public.produits.id;


--
-- Name: sessions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sessions (
    id character varying(255) NOT NULL,
    user_id bigint,
    ip_address character varying(45),
    user_agent text,
    payload text NOT NULL,
    last_activity integer NOT NULL
);


ALTER TABLE public.sessions OWNER TO postgres;

--
-- Name: stocks_entrees; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.stocks_entrees (
    id bigint NOT NULL,
    produit_id bigint NOT NULL,
    fournisseur_id bigint,
    quantite integer NOT NULL,
    date_entree date NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    user_id bigint,
    numero_lot character varying(255),
    date_expiration date,
    entrepot_id bigint
);


ALTER TABLE public.stocks_entrees OWNER TO postgres;

--
-- Name: stocks_entrees_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.stocks_entrees_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.stocks_entrees_id_seq OWNER TO postgres;

--
-- Name: stocks_entrees_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.stocks_entrees_id_seq OWNED BY public.stocks_entrees.id;


--
-- Name: stocks_sorties; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.stocks_sorties (
    id bigint NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    user_id bigint,
    quantite integer,
    date_sortie date,
    motif text,
    produit_id bigint NOT NULL,
    stock_entree_id bigint,
    numero_bon character varying(255),
    statut character varying(255) DEFAULT 'brouillon'::character varying NOT NULL,
    client character varying(255),
    entrepot_id bigint
);


ALTER TABLE public.stocks_sorties OWNER TO postgres;

--
-- Name: stocks_sorties_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.stocks_sorties_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.stocks_sorties_id_seq OWNER TO postgres;

--
-- Name: stocks_sorties_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.stocks_sorties_id_seq OWNED BY public.stocks_sorties.id;


--
-- Name: unite_mesures; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.unite_mesures (
    id bigint NOT NULL,
    code character varying(255) NOT NULL,
    nom character varying(255) NOT NULL,
    symbole character varying(255),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.unite_mesures OWNER TO postgres;

--
-- Name: unite_mesures_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.unite_mesures_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.unite_mesures_id_seq OWNER TO postgres;

--
-- Name: unite_mesures_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.unite_mesures_id_seq OWNED BY public.unite_mesures.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: categories id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories ALTER COLUMN id SET DEFAULT nextval('public.categories_id_seq'::regclass);


--
-- Name: entrepots id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.entrepots ALTER COLUMN id SET DEFAULT nextval('public.entrepots_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: fournisseurs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fournisseurs ALTER COLUMN id SET DEFAULT nextval('public.fournisseurs_id_seq'::regclass);


--
-- Name: jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jobs ALTER COLUMN id SET DEFAULT nextval('public.jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: produits id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits ALTER COLUMN id SET DEFAULT nextval('public.produits_id_seq'::regclass);


--
-- Name: stocks_entrees id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_entrees ALTER COLUMN id SET DEFAULT nextval('public.stocks_entrees_id_seq'::regclass);


--
-- Name: stocks_sorties id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_sorties ALTER COLUMN id SET DEFAULT nextval('public.stocks_sorties_id_seq'::regclass);


--
-- Name: unite_mesures id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.unite_mesures ALTER COLUMN id SET DEFAULT nextval('public.unite_mesures_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: cache; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.cache (key, value, expiration) FROM stdin;
\.


--
-- Data for Name: cache_locks; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.cache_locks (key, owner, expiration) FROM stdin;
\.


--
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.categories (id, nom, description, created_at, updated_at, reference) FROM stdin;
2	SAVONY	savony vaingana	2025-07-15 05:54:45	2025-07-15 05:54:45	SAV
46	POPO 2000	LJKMKLQS JMQS SQS QSFQSLFH LQSD	2025-07-26 06:05:34	2025-07-26 06:05:50	POP
47	CATEGORIE POO	POO DE 2L	2025-07-26 12:30:33	2025-07-26 12:30:33	POO
48	FOP 400	FOP 400 DE PO	2025-07-26 12:36:04	2025-07-26 12:36:04	FOP
3	BISCUITS	BISCUIT SALLÉ E SUCRÉ	2025-07-15 06:57:22	2025-07-16 06:42:10	BISS
12	BOISSON	BOISSON GAZEUX, BOISSON ALCOOLISÉ GM ET PM	2025-07-15 07:16:29	2025-07-16 06:51:37	BOI
4	NOUILLE INSTANTANÉ	NOUILLE : SEDAP, PRESTO ETC...	2025-07-15 06:58:32	2025-07-16 06:53:13	NOU
14	NETOYAGE	PRODUIT DE NETOYAGE	2025-07-17 06:37:10	2025-07-17 06:37:10	NET
15	EPICE	EPICE DE CUISINE	2025-07-17 06:37:55	2025-07-17 06:37:55	EPI
49	POPO	SDF QKLSFNQ LSD	2025-07-26 16:20:53	2025-07-26 16:20:53	PO5
50	SCOTCH	STCOTH PM OU GM	2025-08-02 04:25:18	2025-08-02 04:25:18	SCT
11	FOURNITURES	Fourniture de bureau	2025-07-15 07:12:55	2025-07-17 07:19:12	FRB
71	ATA TEST	\N	2025-08-05 16:11:39	2025-08-05 16:11:39	ATA
77	POPO	\N	2025-08-05 16:16:54	2025-08-05 16:16:54	POPO
13	TEST	TEST DE CREATION DE CATEGORIE	2025-07-17 02:19:04	2025-07-19 03:20:50	TST
79	LOLO 450	QSDHFJQHS LQS FJQSKLJD FQSDFQSF	2025-08-05 16:17:45	2025-08-05 16:17:45	LOLO
17	ELECTRIQUE	MATERIEL ELECTRIQUE	2025-07-17 07:25:13	2025-07-19 03:35:14	ELC
81	KITEST	KITEST DESCRIPTION	2025-08-07 01:15:29	2025-08-07 01:15:29	KIT
31	ENVELOPPE	ENVELOPPE	2025-07-22 02:29:48	2025-07-22 02:35:15	ENV
32	YAOURT	YAOURT MIS EN POT	2025-07-22 02:38:26	2025-07-22 02:38:26	YRT
83	FITEST CATEGORIE	FITEST CATEGORIE DESCRIPTION	2025-08-07 01:20:57	2025-08-07 01:20:57	FIT
85	IOO CATE	IOO CATE DESC	2025-08-07 01:23:23	2025-08-07 01:23:23	IOO
87	JIK CATE	JIK CATE DESC	2025-08-07 01:29:17	2025-08-07 01:29:17	JIK
88	popo 200	popo description	2025-08-07 01:31:01	2025-08-07 01:31:01	popo
89	sasa sasas	sasa description	2025-08-07 01:34:03	2025-08-07 01:34:03	sas
91	hikoko	hikoko description	2025-08-07 01:36:22	2025-08-07 01:36:22	hik
\.


--
-- Data for Name: entrepots; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.entrepots (id, nom, emplacement, created_at, updated_at) FROM stdin;
1	magasin x01	barazy kely	2025-08-08 14:27:39	2025-08-08 14:27:39
2	magasin x02	bazary kely 2	2025-08-09 03:58:19	2025-08-09 03:58:19
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: fournisseurs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.fournisseurs (id, nom, email, telephone, adresse, created_at, updated_at, statut) FROM stdin;
3	UOU LABEL	uoulab@gmail.com	+261347788812	TOAMASINA	2025-07-22 16:40:08	2025-07-22 16:40:08	en attente
4	WG Entreprise	wgentreprise@gmail.com	+261345587941	TOAMASINA, Anjoma Lot 15 B01	2025-07-22 16:46:22	2025-07-22 16:46:22	en attente
6	LAV SARL	\N	+261324578945	\N	2025-07-22 16:52:28	2025-07-22 16:52:28	en attente
5	SIG MADA	sigmada@gmail.com	+261345587941	TOAMASINA, Anjoma Lot 15 B01	2025-07-22 16:51:43	2025-07-23 08:00:57	en attente
8	QIC ALK SARL	qc.alka.sarl@gmail.mail	+261330240050	\N	2025-07-23 07:15:09	2025-07-23 08:01:30	en attente
2	TAR 500 SARL	tar@gmail.com	+261324578945	TOAMASINA	2025-07-22 16:37:26	2025-07-23 08:02:14	en attente
7	MOMO Society	mama@society.mg	+261335548612	TOAMASINA, Ampasimazava Lot 54	2025-07-22 16:57:51	2025-07-23 08:08:22	en attente
1	MADA PRO	\N	+261324578965	\N	2025-07-22 16:34:25	2025-07-23 08:08:47	en attente
9	Gabriel Andriamahafaly	gestalkana@gmail.com	+261344879509	TOAMASINA	2025-07-23 08:13:28	2025-07-23 08:13:28	en attente
10	ANDRANA 0727	andrana0727@gmail.com	044879509	TOAMASINA	2025-08-02 04:28:03	2025-08-02 04:28:03	en attente
\.


--
-- Data for Name: job_batches; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.job_batches (id, name, total_jobs, pending_jobs, failed_jobs, failed_job_ids, options, cancelled_at, created_at, finished_at) FROM stdin;
\.


--
-- Data for Name: jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.jobs (id, queue, payload, attempts, reserved_at, available_at, created_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	0001_01_01_000000_create_users_table	1
2	0001_01_01_000001_create_cache_table	1
3	0001_01_01_000002_create_jobs_table	1
4	2025_07_10_080521_create_categories_table	1
5	2025_07_10_080548_create_produits_table	1
6	2025_07_10_080718_create_fournisseurs_table	1
7	2025_07_10_084356_create_stocks_entrees_table	1
8	2025_07_10_084433_create_stocks_sorties_table	1
9	2025_07_11_041417_add_user_id_to_entrees_and_sorties_tables	1
10	2025_07_14_153732_add_reference_and_code_produit_columns_to_categories_and_produits_tables	1
12	2025_07_18_034549_update_foreign_key_on_produits_table	2
18	2025_07_18_130253_add_prix_achat_to_produits_table	3
19	2025_07_19_045532_add_numero_lot_and_date_expiration_to_stock_entrees_table	3
20	2025_07_19_050822_create_unite_mesures_table	3
21	2025_07_19_051612_add_unite_mesure_id_to_produits_table	3
22	2025_07_21_081302_add_columns_to_stocks_sorties_table	4
23	2025_07_21_081527_add_columns_with_foreign_keys_to_stocks_sorties_table	4
24	2025_07_22_155851_add_statut_to_fournisseurs_table	5
25	2025_08_02_030834_add_fields_to_stocks_sorties_table	6
26	2025_08_02_033933_make_stock_entree_id_nullable_on_stocks_sorties_table	7
28	2025_08_02_141250_create_entrepots_table	8
29	2025_08_02_141648_add_entrepot_id_to_stocks_tables	8
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: produits; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produits (id, nom, description, prix_unitaire, categorie_id, created_at, updated_at, code_produit, prix_achat, unite_mesure_id) FROM stdin;
9	STYLO	FOURNITURE DE BUREAU	500.00	11	2025-07-18 12:31:02	2025-07-18 12:31:02	FRB-S-001	\N	\N
12	SAVONY FOTSY	SAVONY VAINGANA TSOTRA FOTSY	500.00	2	2025-07-18 13:15:02	2025-07-18 13:15:02	SAV-002	\N	\N
13	SAVONY BOOM	SAVONY VOVONY BOOM	500.00	2	2025-07-18 13:18:33	2025-07-18 13:18:33	SAV-003	\N	\N
14	CAHIER 200 PAGES	CAHIER 200 PAGES LAUREAT	2000.00	11	2025-07-18 13:27:57	2025-07-18 13:27:57	FRB-C-001	\N	\N
19	PRODUIT 2005	TEST KELY FOTSINY ALOHA	8000.00	13	2025-07-18 14:01:15	2025-07-18 14:01:15	TEST-005	\N	\N
20	montre	MONTRE ROLEX	20000.00	13	2025-07-18 14:13:44	2025-07-18 14:13:44	TEST-006	\N	\N
21	PAPIER A4	PAPIER A4 PAQUET DE 40	5000.00	11	2025-07-18 14:16:49	2025-07-18 14:16:49	FRB-P-001	\N	\N
22	PRODUIT TEST	DETAILS TEST DE CREATION	4500.00	13	2025-07-19 06:02:20	2025-07-19 06:02:20	TEST-007	\N	\N
23	TEST APR SUP CAT	TEST APRÈS SUPPRESSION CATEGORIE	9000.00	13	2025-07-19 16:56:15	2025-07-19 16:56:15	TEST-008	\N	\N
24	FOURNITURES test	test de creation de fournitures de bureau	3000.00	11	2025-07-19 17:04:33	2025-07-19 17:04:33	FRB-T-001	\N	\N
25	TEST 8000	TEST IHANY KOA	1500.00	13	2025-07-19 17:10:44	2025-07-19 17:10:44	TEST-009	\N	\N
26	SAVONY TEST	SAVOYROA	2400.00	13	2025-07-19 17:15:22	2025-07-19 17:15:22	SAV-T-001	\N	\N
27	FOURNITURES test	TEST DE FOURNITURE	115000.00	11	2025-07-19 17:35:09	2025-07-19 17:35:09	FRB-T-002	\N	\N
28	FOURNITURES	creation test	150000.00	11	2025-07-19 17:39:03	2025-07-19 17:39:03	FRB-T-003	\N	\N
30	TEST	TEST	100.00	13	2025-07-19 17:45:16	2025-07-19 17:45:16	TEST-011	\N	\N
32	beaufort	\N	5000.00	12	2025-07-19 17:55:06	2025-07-19 17:55:06	BOIS-B-001	\N	\N
33	TEST	test de creation avec tippy	4500.00	13	2025-07-19 18:02:24	2025-07-19 18:02:24	TEST-012	\N	\N
34	Andrana	Mandrana creation fotsiny	45000.00	13	2025-07-20 07:21:33	2025-07-20 07:21:33	TEST-013	\N	\N
35	FOURNITURES de test	TEST FOURNITURE KELY	3000.00	13	2025-07-20 08:09:58	2025-07-20 08:09:58	FRT	\N	\N
8	NOSY	SAVONY NOSY AMIN'NY SACHET Lux	2000.00	2	2025-07-18 12:19:13	2025-08-07 14:55:13	SAV-001	\N	5
10	SAVONY EXTRA PROPRE	SAVONY VOVONY ROSE	600.00	2	2025-07-18 12:59:11	2025-07-21 17:04:40	SAV-00	\N	\N
11	EPONGE	EPONGE BLEU	400.00	11	2025-07-18 13:07:56	2025-07-22 02:20:05	FRB	\N	\N
39	PRODUIT 400	LSFJMLSKDJ MSDF SKQ  DFQS	4000.00	13	2025-07-26 06:06:43	2025-07-26 06:06:43	SAV-0040	\N	\N
40	Produit POO	CAT POR ODQOSF JQ DJFQSMLKJ F	40000.00	46	2025-07-26 12:31:19	2025-07-26 12:31:19	POO-P-200	\N	\N
41	SCOTCH PRINCE PACKING TAPE	ROULEAU DE 500M ROULEAU DE 500M	2500.00	50	2025-08-02 04:27:02	2025-08-02 04:27:02	SCT-P-001	\N	\N
42	BOLO	\N	200.00	3	2025-08-07 01:14:58	2025-08-07 01:14:58	BIS-BOLO	\N	\N
45	PRODUIT CHROM	\N	2000.00	13	2025-08-07 02:32:00	2025-08-07 02:32:00	TEST-P-001	\N	\N
46	PRODUIT FOX	\N	1000.00	13	2025-08-07 02:33:13	2025-08-07 02:33:13	TEST-PF-001	\N	\N
47	SAVONY ZAKURO		1600.00	2	2025-08-07 02:41:13	2025-08-07 03:26:56	SAV-Z001	\N	2
\.


--
-- Data for Name: sessions; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.sessions (id, user_id, ip_address, user_agent, payload, last_activity) FROM stdin;
b5OiGSu9cUeGxtSWxlVSk8zhJaZM7W8n16ww6zJt	2	127.0.0.1	Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/138.0.0.0 Safari/537.36	YTo0OntzOjY6Il90b2tlbiI7czo0MDoiMlN5T3dUZ1M1WmR1VnpsV2lrOTVER1RzQmlVREx2V1libUZva2JyeSI7czo5OiJfcHJldmlvdXMiO2E6MTp7czozOiJ1cmwiO3M6MzU6Imh0dHA6Ly9sb2NhbGhvc3Q6ODAwMC9zdG9ja3NFbnRyZWVzIjt9czo2OiJfZmxhc2giO2E6Mjp7czozOiJvbGQiO2E6MDp7fXM6MzoibmV3IjthOjA6e319czo1MDoibG9naW5fd2ViXzU5YmEzNmFkZGMyYjJmOTQwMTU4MGYwMTRjN2Y1OGVhNGUzMDk4OWQiO2k6Mjt9	1754711899
\.


--
-- Data for Name: stocks_entrees; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.stocks_entrees (id, produit_id, fournisseur_id, quantite, date_entree, created_at, updated_at, user_id, numero_lot, date_expiration, entrepot_id) FROM stdin;
6	8	3	450	2025-07-23	2025-07-23 15:34:16	2025-07-23 15:34:16	2	\N	\N	\N
8	9	5	100	2025-07-23	2025-07-23 15:42:55	2025-07-23 15:42:55	2	\N	\N	\N
11	40	4	400	2025-07-26	2025-07-26 12:32:05	2025-07-26 12:32:05	2	\N	2025-07-26	\N
13	32	\N	400	2025-07-26	2025-07-26 12:44:14	2025-07-26 12:44:14	2	\N	2026-11-26	\N
10	23	7	800	2025-07-23	2025-07-23 17:32:17	2025-07-29 12:33:13	2	\N	2026-07-31	\N
9	12	6	50	2025-07-23	2025-07-23 15:43:31	2025-07-29 08:19:47	2	\N	2026-07-29	\N
7	12	6	100	2025-07-23	2025-07-23 15:34:35	2025-07-29 08:20:36	2	\N	2026-07-31	\N
12	32	5	405	2025-07-26	2025-07-26 12:43:10	2025-07-29 08:21:44	2	\N	2026-07-26	\N
1	9	3	155	2025-07-23	2025-07-23 15:29:47	2025-07-29 12:33:45	2	\N	2026-12-30	\N
4	25	4	400	2025-07-23	2025-07-23 15:33:14	2025-07-29 08:22:45	2	\N	2026-10-30	\N
3	25	4	500	2025-07-23	2025-07-23 15:31:40	2025-07-29 08:23:33	2	\N	2026-07-29	\N
2	9	3	405	2025-07-23	2025-07-23 15:31:18	2025-07-30 03:35:23	2	\N	2025-07-30	\N
14	21	6	405	2025-07-29	2025-07-29 08:06:02	2025-07-29 08:38:35	2	\N	2026-07-01	\N
5	12	6	155	2025-07-23	2025-07-23 15:33:44	2025-07-30 03:35:33	2	\N	2025-07-30	\N
15	39	2	45	2025-07-30	2025-07-30 03:36:30	2025-07-30 03:36:30	2	\N	2027-07-30	\N
16	41	10	400	2025-08-02	2025-08-02 04:28:39	2025-08-02 04:28:39	2	\N	2026-10-07	\N
17	22	6	10	2025-08-03	2025-08-03 03:15:19	2025-08-03 03:15:19	2	\N	2025-08-03	\N
\.


--
-- Data for Name: stocks_sorties; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.stocks_sorties (id, created_at, updated_at, user_id, quantite, date_sortie, motif, produit_id, stock_entree_id, numero_bon, statut, client, entrepot_id) FROM stdin;
5	2025-08-02 03:41:44	2025-08-02 03:41:44	2	40	2025-08-02	\N	8	\N	BS202508-001	brouillon	\N	\N
6	2025-08-02 04:03:24	2025-08-02 04:03:24	2	70	2025-08-02	\N	12	\N	BS202508-002	brouillon	\N	\N
7	2025-08-02 04:03:24	2025-08-02 04:03:24	2	20	2025-08-02	\N	40	\N	BS202508-002	brouillon	\N	\N
8	2025-08-02 04:04:04	2025-08-02 04:04:04	2	50	2025-08-02	\N	40	\N	BS202508-003	brouillon	\N	\N
9	2025-08-02 04:23:41	2025-08-02 04:23:41	2	25	2025-08-02	\N	21	14	BS202508-004	valide	\N	\N
10	2025-08-02 04:29:53	2025-08-02 04:29:53	2	120	2025-08-02	\N	41	16	BS202508-005	valide	\N	\N
11	2025-08-02 06:29:57	2025-08-02 06:29:57	2	40	2025-08-02	\N	25	4	BS202508-006	valide	\N	\N
12	2025-08-02 06:29:57	2025-08-02 06:29:57	2	20	2025-08-02	\N	40	11	BS202508-006	valide	\N	\N
\.


--
-- Data for Name: unite_mesures; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.unite_mesures (id, code, nom, symbole, created_at, updated_at) FROM stdin;
1	KG	kilogramme	kg	2025-08-07 01:59:48	2025-08-07 01:59:48
2	CART	Carton	cart	2025-08-07 02:15:51	2025-08-07 02:15:51
3	L	Litre	l	2025-08-07 02:19:31	2025-08-07 02:19:31
4	SAC	Sac	gony	2025-08-07 02:20:52	2025-08-07 02:20:52
5	PC	Pièce	pc	2025-08-07 02:22:20	2025-08-07 02:26:14
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
2	Gabriel	gestalkana@gmail.com	2025-07-14 20:13:17	$2y$12$VHp91KWoKBVm8WxbTACise2SL4bff5t.hLv7JtouW2y7FF5EjDzO6	\N	2025-07-14 20:13:17	2025-07-14 20:13:17
\.


--
-- Name: categories_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.categories_id_seq', 91, true);


--
-- Name: entrepots_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.entrepots_id_seq', 2, true);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: fournisseurs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.fournisseurs_id_seq', 10, true);


--
-- Name: jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 29, true);


--
-- Name: produits_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.produits_id_seq', 47, true);


--
-- Name: stocks_entrees_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.stocks_entrees_id_seq', 17, true);


--
-- Name: stocks_sorties_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.stocks_sorties_id_seq', 12, true);


--
-- Name: unite_mesures_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.unite_mesures_id_seq', 5, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 2, true);


--
-- Name: cache_locks cache_locks_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cache_locks
    ADD CONSTRAINT cache_locks_pkey PRIMARY KEY (key);


--
-- Name: cache cache_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cache
    ADD CONSTRAINT cache_pkey PRIMARY KEY (key);


--
-- Name: categories categories_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories
    ADD CONSTRAINT categories_pkey PRIMARY KEY (id);


--
-- Name: categories categories_reference_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories
    ADD CONSTRAINT categories_reference_unique UNIQUE (reference);


--
-- Name: entrepots entrepots_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.entrepots
    ADD CONSTRAINT entrepots_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: fournisseurs fournisseurs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fournisseurs
    ADD CONSTRAINT fournisseurs_pkey PRIMARY KEY (id);


--
-- Name: job_batches job_batches_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.job_batches
    ADD CONSTRAINT job_batches_pkey PRIMARY KEY (id);


--
-- Name: jobs jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jobs
    ADD CONSTRAINT jobs_pkey PRIMARY KEY (id);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: produits produits_code_produit_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits
    ADD CONSTRAINT produits_code_produit_unique UNIQUE (code_produit);


--
-- Name: produits produits_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits
    ADD CONSTRAINT produits_pkey PRIMARY KEY (id);


--
-- Name: sessions sessions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sessions
    ADD CONSTRAINT sessions_pkey PRIMARY KEY (id);


--
-- Name: stocks_entrees stocks_entrees_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_entrees
    ADD CONSTRAINT stocks_entrees_pkey PRIMARY KEY (id);


--
-- Name: stocks_sorties stocks_sorties_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_sorties
    ADD CONSTRAINT stocks_sorties_pkey PRIMARY KEY (id);


--
-- Name: unite_mesures unite_mesures_code_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.unite_mesures
    ADD CONSTRAINT unite_mesures_code_unique UNIQUE (code);


--
-- Name: unite_mesures unite_mesures_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.unite_mesures
    ADD CONSTRAINT unite_mesures_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: jobs_queue_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX jobs_queue_index ON public.jobs USING btree (queue);


--
-- Name: sessions_last_activity_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX sessions_last_activity_index ON public.sessions USING btree (last_activity);


--
-- Name: sessions_user_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX sessions_user_id_index ON public.sessions USING btree (user_id);


--
-- Name: produits produits_categorie_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits
    ADD CONSTRAINT produits_categorie_id_foreign FOREIGN KEY (categorie_id) REFERENCES public.categories(id) ON DELETE SET NULL;


--
-- Name: produits produits_unite_mesure_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits
    ADD CONSTRAINT produits_unite_mesure_id_foreign FOREIGN KEY (unite_mesure_id) REFERENCES public.unite_mesures(id) ON DELETE SET NULL;


--
-- Name: stocks_entrees stocks_entrees_entrepot_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_entrees
    ADD CONSTRAINT stocks_entrees_entrepot_id_foreign FOREIGN KEY (entrepot_id) REFERENCES public.entrepots(id);


--
-- Name: stocks_entrees stocks_entrees_fournisseur_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_entrees
    ADD CONSTRAINT stocks_entrees_fournisseur_id_foreign FOREIGN KEY (fournisseur_id) REFERENCES public.fournisseurs(id) ON DELETE SET NULL;


--
-- Name: stocks_entrees stocks_entrees_produit_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_entrees
    ADD CONSTRAINT stocks_entrees_produit_id_foreign FOREIGN KEY (produit_id) REFERENCES public.produits(id) ON DELETE CASCADE;


--
-- Name: stocks_entrees stocks_entrees_user_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_entrees
    ADD CONSTRAINT stocks_entrees_user_id_foreign FOREIGN KEY (user_id) REFERENCES public.users(id) ON DELETE SET NULL;


--
-- Name: stocks_sorties stocks_sorties_entrepot_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_sorties
    ADD CONSTRAINT stocks_sorties_entrepot_id_foreign FOREIGN KEY (entrepot_id) REFERENCES public.entrepots(id);


--
-- Name: stocks_sorties stocks_sorties_produit_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_sorties
    ADD CONSTRAINT stocks_sorties_produit_id_foreign FOREIGN KEY (produit_id) REFERENCES public.produits(id) ON DELETE CASCADE;


--
-- Name: stocks_sorties stocks_sorties_stock_entree_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_sorties
    ADD CONSTRAINT stocks_sorties_stock_entree_id_foreign FOREIGN KEY (stock_entree_id) REFERENCES public.stocks_entrees(id) ON DELETE CASCADE;


--
-- Name: stocks_sorties stocks_sorties_user_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stocks_sorties
    ADD CONSTRAINT stocks_sorties_user_id_foreign FOREIGN KEY (user_id) REFERENCES public.users(id) ON DELETE SET NULL;


--
-- PostgreSQL database dump complete
--

--
-- Database "dbmagasin" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: dbmagasin; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE dbmagasin WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE dbmagasin OWNER TO postgres;

\connect dbmagasin

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "gesta" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: gesta; Type: DATABASE; Schema: -; Owner: gesta
--

CREATE DATABASE gesta WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE gesta OWNER TO gesta;

\connect gesta

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "gestiondeventes" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: gestiondeventes; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE gestiondeventes WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE gestiondeventes OWNER TO postgres;

\connect gestiondeventes

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: clients; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.clients (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    prenom character varying(255),
    contact character varying(255),
    adresse character varying(255),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    nif character varying(255),
    stat character varying(255),
    email character varying(255)
);


ALTER TABLE public.clients OWNER TO postgres;

--
-- Name: clients_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.clients_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.clients_id_seq OWNER TO postgres;

--
-- Name: clients_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.clients_id_seq OWNED BY public.clients.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: ligne_ventes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ligne_ventes (
    id bigint NOT NULL,
    reference character varying(255) NOT NULL,
    client_id bigint NOT NULL,
    date_vente date NOT NULL,
    montant_total numeric(10,2) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.ligne_ventes OWNER TO postgres;

--
-- Name: ligne_ventes_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.ligne_ventes_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.ligne_ventes_id_seq OWNER TO postgres;

--
-- Name: ligne_ventes_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.ligne_ventes_id_seq OWNED BY public.ligne_ventes.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    expires_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: produits; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produits (
    id bigint NOT NULL,
    nom_produit character varying(255) NOT NULL,
    description character varying(255) NOT NULL,
    prix double precision NOT NULL,
    quantite integer NOT NULL,
    image character varying(255),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.produits OWNER TO postgres;

--
-- Name: produits_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.produits_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.produits_id_seq OWNER TO postgres;

--
-- Name: produits_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.produits_id_seq OWNED BY public.produits.id;


--
-- Name: reference_monthlies; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reference_monthlies (
    id bigint NOT NULL,
    year integer NOT NULL,
    month integer NOT NULL,
    current_number integer DEFAULT 0 NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.reference_monthlies OWNER TO postgres;

--
-- Name: reference_monthlies_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.reference_monthlies_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.reference_monthlies_id_seq OWNER TO postgres;

--
-- Name: reference_monthlies_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.reference_monthlies_id_seq OWNED BY public.reference_monthlies.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: ventes; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.ventes (
    id bigint NOT NULL,
    produit_id bigint NOT NULL,
    prix numeric(10,2) NOT NULL,
    montant numeric(10,2) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.ventes OWNER TO postgres;

--
-- Name: ventes_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.ventes_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.ventes_id_seq OWNER TO postgres;

--
-- Name: ventes_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.ventes_id_seq OWNED BY public.ventes.id;


--
-- Name: clients id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.clients ALTER COLUMN id SET DEFAULT nextval('public.clients_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: ligne_ventes id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ligne_ventes ALTER COLUMN id SET DEFAULT nextval('public.ligne_ventes_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: produits id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits ALTER COLUMN id SET DEFAULT nextval('public.produits_id_seq'::regclass);


--
-- Name: reference_monthlies id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reference_monthlies ALTER COLUMN id SET DEFAULT nextval('public.reference_monthlies_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Name: ventes id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ventes ALTER COLUMN id SET DEFAULT nextval('public.ventes_id_seq'::regclass);


--
-- Data for Name: clients; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.clients (id, nom, prenom, contact, adresse, created_at, updated_at, nif, stat, email) FROM stdin;
1	Antone Stokes	Altenwerth	(616) 561-7832	1335 Sipes Lane Apt. 064\nSouth Brielle, WA 18156	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
2	Samanta Koepp	Hilpert	1-626-624-7113	974 Rosamond Valleys\nLeannonbury, NY 43146-5053	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
3	Mrs. Verla Reinger	Wilkinson	254-225-5438	92457 Jaleel Lodge\nNorth Abigayle, WI 36874-2817	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
4	Delphine Stracke	Konopelski	847.553.4497	117 Hodkiewicz Plaza\nLittleside, OK 46973-3588	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
5	Malika Jacobi	Mraz	(404) 690-8867	74854 Doug Shore Suite 890\nVellamouth, HI 80687	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
6	Telly Deckow	Stoltenberg	+1 (864) 787-9717	4769 Bode Shores\nRobertschester, AR 40531	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
7	Nickolas Sanford	Tromp	+1-715-779-6428	99965 Christiansen Junctions\nMosciskimouth, DE 42748-2621	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
8	Mrs. Jacynthe Tillman	Haley	220-772-9494	99474 Dane Motorway Suite 491\nNorth Jarred, DE 19102-8510	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
9	Jackie Schoen	D'Amore	+1-854-632-2643	3847 Duane Locks\nLake Kelley, NV 77345-8927	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
10	Constance Gerhold	Boehm	620-436-0380	570 Jermain Route\nOttofurt, CA 37606-3467	2025-04-16 10:07:17	2025-04-16 10:07:17	\N	\N	\N
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: ligne_ventes; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ligne_ventes (id, reference, client_id, date_vente, montant_total, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
28	2024_08_10_094550_create_produits_table	1
29	2014_10_12_000000_create_users_table	2
30	2014_10_12_100000_create_password_reset_tokens_table	2
31	2019_08_19_000000_create_failed_jobs_table	2
32	2019_12_14_000001_create_personal_access_tokens_table	2
33	2024_08_10_094305_create_ventes_table	2
34	2024_08_10_094323_create_clients_table	2
35	2024_08_21_152604_add_nif_stat_email_to_clients_table	2
36	2025_04_16_065754_create_ligne_ventes_table	2
37	2025_04_16_095630_create_reference_monthlies_table	2
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, expires_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: produits; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produits (id, nom_produit, description, prix, quantite, image, created_at, updated_at) FROM stdin;
1	et	Quia harum possimus minima voluptate soluta ex.	5834.08	46	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
2	eius	Aliquid aut aspernatur in voluptatem tempora.	73161.83	36	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
3	fugit	Itaque delectus laboriosam excepturi et vel adipisci.	57341.65	86	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
4	laudantium	Voluptas est aliquam aperiam sed ut rem.	66485.16	70	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
5	minus	Amet quo ex quidem laborum.	7880.54	12	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
6	temporibus	Molestiae est nisi voluptatibus non molestiae sed error.	28729.11	85	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
7	at	Ea qui ut nam magni minima.	10394.56	41	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
8	eveniet	Autem voluptatibus ut sit dolores sed eaque.	97588.42	12	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
9	nihil	Asperiores temporibus commodi quas architecto rerum magni harum.	48307.83	77	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
10	voluptas	Sed sit qui expedita reprehenderit ut sit dolorum.	13646.07	91	\N	2025-04-16 10:07:17	2025-04-16 10:07:17
\.


--
-- Data for Name: reference_monthlies; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reference_monthlies (id, year, month, current_number, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: ventes; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ventes (id, produit_id, prix, montant, created_at, updated_at) FROM stdin;
\.


--
-- Name: clients_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.clients_id_seq', 10, true);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: ligne_ventes_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.ligne_ventes_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 37, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: produits_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.produits_id_seq', 10, true);


--
-- Name: reference_monthlies_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reference_monthlies_id_seq', 1, false);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: ventes_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.ventes_id_seq', 1, false);


--
-- Name: clients clients_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_email_unique UNIQUE (email);


--
-- Name: clients clients_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: ligne_ventes ligne_ventes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ligne_ventes
    ADD CONSTRAINT ligne_ventes_pkey PRIMARY KEY (id);


--
-- Name: ligne_ventes ligne_ventes_reference_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ligne_ventes
    ADD CONSTRAINT ligne_ventes_reference_unique UNIQUE (reference);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: produits produits_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits
    ADD CONSTRAINT produits_pkey PRIMARY KEY (id);


--
-- Name: reference_monthlies reference_monthlies_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reference_monthlies
    ADD CONSTRAINT reference_monthlies_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: ventes ventes_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ventes
    ADD CONSTRAINT ventes_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- Name: ligne_ventes ligne_ventes_client_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ligne_ventes
    ADD CONSTRAINT ligne_ventes_client_id_foreign FOREIGN KEY (client_id) REFERENCES public.clients(id) ON DELETE CASCADE;


--
-- Name: ventes ventes_produit_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.ventes
    ADD CONSTRAINT ventes_produit_id_foreign FOREIGN KEY (produit_id) REFERENCES public.produits(id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

--
-- Database "hotellerie" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: hotellerie; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE hotellerie WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE hotellerie OWNER TO postgres;

\connect hotellerie

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: chambre; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.chambre (
    idchambre integer NOT NULL,
    "étage" integer,
    type text,
    nombrelit integer
);


ALTER TABLE public.chambre OWNER TO postgres;

--
-- Name: client; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.client (
    idclient integer NOT NULL,
    nom text,
    prenom text,
    adresse text
);


ALTER TABLE public.client OWNER TO postgres;

--
-- Name: hotel; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.hotel (
    idhotel integer NOT NULL,
    adresse text,
    "catégorie" text,
    nomhotel text,
    ville text
);


ALTER TABLE public.hotel OWNER TO postgres;

--
-- Name: reservation; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reservation (
    idclient integer,
    idhotel integer,
    idchambre integer,
    datereservation date
);


ALTER TABLE public.reservation OWNER TO postgres;

--
-- Data for Name: chambre; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.chambre (idchambre, "étage", type, nombrelit) FROM stdin;
1	3	familliale	4
\.


--
-- Data for Name: client; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.client (idclient, nom, prenom, adresse) FROM stdin;
1	nomClient1	prenom1	tanamakoa
2	nomclient2	prenom2	vohitsara
3	nomclient3	prenom3	anjoma
\.


--
-- Data for Name: hotel; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.hotel (idhotel, adresse, "catégorie", nomhotel, ville) FROM stdin;
1	tanambao 5	trois étoile	hotel1	toamasina
2	tanamakoa	Ravinala	hotel2	toamasina
3	Morafeno	4 étoile	hotel3	toamasina
\.


--
-- Data for Name: reservation; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reservation (idclient, idhotel, idchambre, datereservation) FROM stdin;
1	1	1	2024-01-15
2	1	1	2024-01-15
3	1	1	2024-01-14
1	2	1	2024-01-15
3	2	1	2024-01-14
3	1	1	2024-01-15
3	1	1	2024-01-14
1	3	1	2024-01-11
3	1	1	2024-01-31
\.


--
-- Name: chambre chambre_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.chambre
    ADD CONSTRAINT chambre_pkey PRIMARY KEY (idchambre);


--
-- Name: client client_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.client
    ADD CONSTRAINT client_pkey PRIMARY KEY (idclient);


--
-- Name: hotel hotel_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.hotel
    ADD CONSTRAINT hotel_pkey PRIMARY KEY (idhotel);


--
-- Name: reservation reservation_idchambre_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation
    ADD CONSTRAINT reservation_idchambre_fkey FOREIGN KEY (idchambre) REFERENCES public.chambre(idchambre);


--
-- Name: reservation reservation_idclient_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation
    ADD CONSTRAINT reservation_idclient_fkey FOREIGN KEY (idclient) REFERENCES public.client(idclient);


--
-- Name: reservation reservation_idhotel_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reservation
    ADD CONSTRAINT reservation_idhotel_fkey FOREIGN KEY (idhotel) REFERENCES public.hotel(idhotel);


--
-- PostgreSQL database dump complete
--

--
-- Database "instituDB" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: instituDB; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "instituDB" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE "instituDB" OWNER TO postgres;

\connect "instituDB"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "institut" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: institut; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE institut WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE institut OWNER TO postgres;

\connect institut

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: etudiant; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.etudiant (
    idetudiant integer NOT NULL,
    nom text,
    prenom text,
    age integer,
    idparcours integer,
    idniveau integer
);


ALTER TABLE public.etudiant OWNER TO postgres;

--
-- Name: formateur; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.formateur (
    idformateur integer NOT NULL,
    nom text,
    prenom text,
    age integer
);


ALTER TABLE public.formateur OWNER TO postgres;

--
-- Name: niveau; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.niveau (
    idniveau integer NOT NULL,
    nomc text
);


ALTER TABLE public.niveau OWNER TO postgres;

--
-- Name: parcours; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.parcours (
    idparcours integer NOT NULL,
    nomparcours text
);


ALTER TABLE public.parcours OWNER TO postgres;

--
-- Data for Name: etudiant; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.etudiant (idetudiant, nom, prenom, age, idparcours, idniveau) FROM stdin;
2	Gaston	Gaston	26	1	3
1	Andri	Gabriel	27	2	1
\.


--
-- Data for Name: formateur; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.formateur (idformateur, nom, prenom, age) FROM stdin;
\.


--
-- Data for Name: niveau; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.niveau (idniveau, nomc) FROM stdin;
1	Licence 1
2	Licence 2
3	Licence 3
\.


--
-- Data for Name: parcours; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.parcours (idparcours, nomparcours) FROM stdin;
1	informatique
2	Gestion
3	Droit
\.


--
-- Name: etudiant etudiant_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.etudiant
    ADD CONSTRAINT etudiant_pkey PRIMARY KEY (idetudiant);


--
-- Name: formateur formateur_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.formateur
    ADD CONSTRAINT formateur_pkey PRIMARY KEY (idformateur);


--
-- Name: niveau niveau_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.niveau
    ADD CONSTRAINT niveau_pkey PRIMARY KEY (idniveau);


--
-- Name: parcours parcours_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.parcours
    ADD CONSTRAINT parcours_pkey PRIMARY KEY (idparcours);


--
-- Name: etudiant etudiant_idniveau_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.etudiant
    ADD CONSTRAINT etudiant_idniveau_fkey FOREIGN KEY (idniveau) REFERENCES public.niveau(idniveau);


--
-- Name: etudiant etudiant_idparcours_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.etudiant
    ADD CONSTRAINT etudiant_idparcours_fkey FOREIGN KEY (idparcours) REFERENCES public.parcours(idparcours);


--
-- PostgreSQL database dump complete
--

--
-- Database "institutDB" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: institutDB; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE "institutDB" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE "institutDB" OWNER TO postgres;

\connect "institutDB"

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: etudiant; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.etudiant (
    idetudiant integer NOT NULL,
    nom text,
    prenom text,
    classe text,
    parcours text,
    age integer
);


ALTER TABLE public.etudiant OWNER TO postgres;

--
-- Data for Name: etudiant; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.etudiant (idetudiant, nom, prenom, classe, parcours, age) FROM stdin;
\.


--
-- Name: etudiant etudiant_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.etudiant
    ADD CONSTRAINT etudiant_pkey PRIMARY KEY (idetudiant);


--
-- PostgreSQL database dump complete
--

--
-- Database "mabase" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: mabase; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE mabase WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE mabase OWNER TO postgres;

\connect mabase

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: client; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.client (
    idcli integer NOT NULL,
    nom text,
    age numeric
);


ALTER TABLE public.client OWNER TO postgres;

--
-- Name: commande; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.commande (
    idcommande integer NOT NULL,
    idproduit integer,
    idcli integer
);


ALTER TABLE public.commande OWNER TO postgres;

--
-- Name: produit; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produit (
    idproduit integer NOT NULL,
    nom text
);


ALTER TABLE public.produit OWNER TO postgres;

--
-- Data for Name: client; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.client (idcli, nom, age) FROM stdin;
1	Gabriel	26
2	Gabriel Andri	26
3	Gabriel Andri	20
4	Rebecca	15
5	Tendry	36
\.


--
-- Data for Name: commande; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.commande (idcommande, idproduit, idcli) FROM stdin;
\.


--
-- Data for Name: produit; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produit (idproduit, nom) FROM stdin;
\.


--
-- Name: client client_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.client
    ADD CONSTRAINT client_pkey PRIMARY KEY (idcli);


--
-- Name: commande commande_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_pkey PRIMARY KEY (idcommande);


--
-- Name: produit produit_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produit
    ADD CONSTRAINT produit_pkey PRIMARY KEY (idproduit);


--
-- Name: commande commande_idcli_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_idcli_fkey FOREIGN KEY (idcli) REFERENCES public.client(idcli);


--
-- Name: commande commande_idproduit_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_idproduit_fkey FOREIGN KEY (idproduit) REFERENCES public.produit(idproduit);


--
-- PostgreSQL database dump complete
--

--
-- Database "magasin" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: magasin; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE magasin WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE magasin OWNER TO postgres;

\connect magasin

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: client; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.client (
    numcli integer NOT NULL,
    nom text,
    prenom text,
    datenaiss date,
    adresse text
);


ALTER TABLE public.client OWNER TO postgres;

--
-- Name: commande; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.commande (
    numco integer NOT NULL,
    numcli integer,
    nump integer,
    quantite integer
);


ALTER TABLE public.commande OWNER TO postgres;

--
-- Name: produit; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produit (
    nump integer NOT NULL,
    designation text,
    prixu numeric,
    CONSTRAINT produit_prixu_check CHECK ((prixu > (0)::numeric))
);


ALTER TABLE public.produit OWNER TO postgres;

--
-- Data for Name: client; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.client (numcli, nom, prenom, datenaiss, adresse) FROM stdin;
1	nom1	prenom1	1997-05-19	tanamakoa
2	nom2	prenom2	1997-05-19	tanamakoa
3	nom3	prenom3	1997-05-19	tanamakoa
\.


--
-- Data for Name: commande; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.commande (numco, numcli, nump, quantite) FROM stdin;
1	1	1	50
2	2	3	40
3	1	3	40
4	1	1	10
5	3	1	10
6	1	3	10
\.


--
-- Data for Name: produit; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produit (nump, designation, prixu) FROM stdin;
1	produit1	500
2	produit2	200
3	produit3	100
\.


--
-- Name: client client_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.client
    ADD CONSTRAINT client_pkey PRIMARY KEY (numcli);


--
-- Name: commande commande_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_pkey PRIMARY KEY (numco);


--
-- Name: produit produit_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produit
    ADD CONSTRAINT produit_pkey PRIMARY KEY (nump);


--
-- Name: commande commande_numcli_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_numcli_fkey FOREIGN KEY (numcli) REFERENCES public.client(numcli);


--
-- Name: commande commande_nump_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.commande
    ADD CONSTRAINT commande_nump_fkey FOREIGN KEY (nump) REFERENCES public.produit(nump);


--
-- PostgreSQL database dump complete
--

--
-- Database "miserasoft" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: miserasoft; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE miserasoft WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE miserasoft OWNER TO postgres;

\connect miserasoft

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: cache; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cache (
    key character varying(255) NOT NULL,
    value text NOT NULL,
    expiration integer NOT NULL
);


ALTER TABLE public.cache OWNER TO postgres;

--
-- Name: cache_locks; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cache_locks (
    key character varying(255) NOT NULL,
    owner character varying(255) NOT NULL,
    expiration integer NOT NULL
);


ALTER TABLE public.cache_locks OWNER TO postgres;

--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: job_batches; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.job_batches (
    id character varying(255) NOT NULL,
    name character varying(255) NOT NULL,
    total_jobs integer NOT NULL,
    pending_jobs integer NOT NULL,
    failed_jobs integer NOT NULL,
    failed_job_ids text NOT NULL,
    options text,
    cancelled_at integer,
    created_at integer NOT NULL,
    finished_at integer
);


ALTER TABLE public.job_batches OWNER TO postgres;

--
-- Name: jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.jobs (
    id bigint NOT NULL,
    queue character varying(255) NOT NULL,
    payload text NOT NULL,
    attempts smallint NOT NULL,
    reserved_at integer,
    available_at integer NOT NULL,
    created_at integer NOT NULL
);


ALTER TABLE public.jobs OWNER TO postgres;

--
-- Name: jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.jobs_id_seq OWNER TO postgres;

--
-- Name: jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.jobs_id_seq OWNED BY public.jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: produits; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produits (
    id bigint NOT NULL,
    nom_produit character varying(255) NOT NULL,
    quantite_stock integer DEFAULT 0 NOT NULL,
    prix_achat numeric(10,2),
    prix_vente numeric(10,2) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.produits OWNER TO postgres;

--
-- Name: produits_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.produits_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.produits_id_seq OWNER TO postgres;

--
-- Name: produits_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.produits_id_seq OWNED BY public.produits.id;


--
-- Name: sessions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sessions (
    id character varying(255) NOT NULL,
    user_id bigint,
    ip_address character varying(45),
    user_agent text,
    payload text NOT NULL,
    last_activity integer NOT NULL
);


ALTER TABLE public.sessions OWNER TO postgres;

--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jobs ALTER COLUMN id SET DEFAULT nextval('public.jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: produits id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits ALTER COLUMN id SET DEFAULT nextval('public.produits_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: cache; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.cache (key, value, expiration) FROM stdin;
\.


--
-- Data for Name: cache_locks; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.cache_locks (key, owner, expiration) FROM stdin;
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: job_batches; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.job_batches (id, name, total_jobs, pending_jobs, failed_jobs, failed_job_ids, options, cancelled_at, created_at, finished_at) FROM stdin;
\.


--
-- Data for Name: jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.jobs (id, queue, payload, attempts, reserved_at, available_at, created_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	0001_01_01_000000_create_users_table	1
2	0001_01_01_000001_create_cache_table	1
3	0001_01_01_000002_create_jobs_table	1
4	2025_03_01_083457_create_produits_table	1
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: produits; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produits (id, nom_produit, quantite_stock, prix_achat, prix_vente, created_at, updated_at) FROM stdin;
1	id	50	\N	725.12	2025-03-01 09:03:25	2025-03-01 09:03:25
2	accusamus	51	\N	671.20	2025-03-01 09:03:25	2025-03-01 09:03:25
3	facilis	11	55.63	378.81	2025-03-01 09:03:25	2025-03-01 09:03:25
4	voluptatem	47	329.53	377.91	2025-03-01 09:03:25	2025-03-01 09:03:25
5	beatae	40	\N	616.24	2025-03-01 09:03:25	2025-03-01 09:03:25
6	omnis	71	137.74	583.69	2025-03-01 09:03:25	2025-03-01 09:03:25
7	laboriosam	34	109.41	110.51	2025-03-01 09:03:25	2025-03-01 09:03:25
8	voluptatem	53	121.59	24.97	2025-03-01 09:03:25	2025-03-01 09:03:25
9	magnam	88	\N	585.50	2025-03-01 09:03:25	2025-03-01 09:03:25
10	dolorem	33	\N	200.14	2025-03-01 09:03:25	2025-03-01 09:03:25
11	corrupti	41	36.07	81.17	2025-03-01 09:03:25	2025-03-01 09:03:25
12	doloremque	81	308.54	831.36	2025-03-01 09:03:25	2025-03-01 09:03:25
13	enim	96	286.98	593.59	2025-03-01 09:03:25	2025-03-01 09:03:25
14	dolorum	54	\N	209.71	2025-03-01 09:03:25	2025-03-01 09:03:25
15	voluptatem	58	\N	611.76	2025-03-01 09:03:25	2025-03-01 09:03:25
16	ut	94	261.05	734.69	2025-03-01 09:03:25	2025-03-01 09:03:25
17	est	89	\N	481.52	2025-03-01 09:03:25	2025-03-01 09:03:25
18	quidem	5	\N	869.04	2025-03-01 09:03:25	2025-03-01 09:03:25
19	sed	10	\N	509.13	2025-03-01 09:03:25	2025-03-01 09:03:25
20	modi	59	\N	494.72	2025-03-01 09:03:25	2025-03-01 09:03:25
21	tempore	69	\N	62.61	2025-03-01 09:05:27	2025-03-01 09:05:27
22	vitae	43	\N	857.54	2025-03-01 09:05:27	2025-03-01 09:05:27
23	illo	34	136.32	889.30	2025-03-01 09:05:27	2025-03-01 09:05:27
24	odit	95	\N	299.16	2025-03-01 09:05:27	2025-03-01 09:05:27
25	quam	1	478.76	406.94	2025-03-01 09:05:27	2025-03-01 09:05:27
26	dicta	41	\N	763.74	2025-03-01 09:05:27	2025-03-01 09:05:27
27	cumque	72	\N	752.24	2025-03-01 09:05:27	2025-03-01 09:05:27
28	ut	82	289.85	624.38	2025-03-01 09:05:27	2025-03-01 09:05:27
29	illo	4	366.67	668.82	2025-03-01 09:05:27	2025-03-01 09:05:27
30	alias	51	202.48	474.05	2025-03-01 09:05:27	2025-03-01 09:05:27
\.


--
-- Data for Name: sessions; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.sessions (id, user_id, ip_address, user_agent, payload, last_activity) FROM stdin;
Hsp8dKK3YMbXTwN0ZAZUWJPCZNMNPVuxiaqJA6aH	\N	127.0.0.1	Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/138.0.0.0 Safari/537.36	YTozOntzOjY6Il90b2tlbiI7czo0MDoiS21Da2lqNE5YOXBuT1BRMFg1ZlRMV3dYVmppbmFJUnljSUVjRlhjTiI7czo5OiJfcHJldmlvdXMiO2E6MTp7czozOiJ1cmwiO3M6MjE6Imh0dHA6Ly9sb2NhbGhvc3Q6ODAwMCI7fXM6NjoiX2ZsYXNoIjthOjI6e3M6Mzoib2xkIjthOjA6e31zOjM6Im5ldyI7YTowOnt9fX0=	1751982159
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
1	Test User	test@example.com	2025-03-01 08:59:02	$2y$12$5n7EwKAhlT3d156ilEDe/OGRjEb1g3wYS7bq8H2IDOeNRvKxy47Cy	c8fwbtpnGg	2025-03-01 08:59:02	2025-03-01 08:59:02
\.


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 4, true);


--
-- Name: produits_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.produits_id_seq', 30, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 2, true);


--
-- Name: cache_locks cache_locks_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cache_locks
    ADD CONSTRAINT cache_locks_pkey PRIMARY KEY (key);


--
-- Name: cache cache_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cache
    ADD CONSTRAINT cache_pkey PRIMARY KEY (key);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: job_batches job_batches_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.job_batches
    ADD CONSTRAINT job_batches_pkey PRIMARY KEY (id);


--
-- Name: jobs jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jobs
    ADD CONSTRAINT jobs_pkey PRIMARY KEY (id);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: produits produits_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produits
    ADD CONSTRAINT produits_pkey PRIMARY KEY (id);


--
-- Name: sessions sessions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sessions
    ADD CONSTRAINT sessions_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: jobs_queue_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX jobs_queue_index ON public.jobs USING btree (queue);


--
-- Name: sessions_last_activity_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX sessions_last_activity_index ON public.sessions USING btree (last_activity);


--
-- Name: sessions_user_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX sessions_user_id_index ON public.sessions USING btree (user_id);


--
-- PostgreSQL database dump complete
--

--
-- Database "miserasoft_l3" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: miserasoft_l3; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE miserasoft_l3 WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE miserasoft_l3 OWNER TO postgres;

\connect miserasoft_l3

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: clients; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.clients (
    id bigint NOT NULL,
    nom character varying(255) NOT NULL,
    prenom character varying(255) NOT NULL,
    date_de_naissance character varying(255) NOT NULL,
    adresse character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.clients OWNER TO postgres;

--
-- Name: clients_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.clients_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.clients_id_seq OWNER TO postgres;

--
-- Name: clients_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.clients_id_seq OWNED BY public.clients.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    expires_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: clients id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.clients ALTER COLUMN id SET DEFAULT nextval('public.clients_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: clients; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.clients (id, nom, prenom, date_de_naissance, adresse, email, created_at, updated_at) FROM stdin;
1	Brock Ryan	Annamae Beier	2015-11-03	40042 Rebecca Terrace Apt. 342\nWest Alexandro, VA 72144-4555	zkub@example.com	2025-05-21 07:52:45	2025-05-21 07:52:45
2	Demetrius Grady IV	Stefan King	2002-11-08	5691 Sipes Harbor\nLake Cassandreland, GA 82252	pgreenholt@example.org	2025-05-22 03:00:21	2025-05-22 03:00:21
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	2014_10_12_000000_create_users_table	1
2	2014_10_12_100000_create_password_reset_tokens_table	1
3	2019_08_19_000000_create_failed_jobs_table	1
4	2019_12_14_000001_create_personal_access_tokens_table	1
5	2025_05_07_124429_create_clients_table	1
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, expires_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Name: clients_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.clients_id_seq', 2, true);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 5, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: clients clients_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- PostgreSQL database dump complete
--

--
-- Database "mitrademaster" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: mitrademaster; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE mitrademaster WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE mitrademaster OWNER TO postgres;

\connect mitrademaster

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: cache; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cache (
    key character varying(255) NOT NULL,
    value text NOT NULL,
    expiration integer NOT NULL
);


ALTER TABLE public.cache OWNER TO postgres;

--
-- Name: cache_locks; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.cache_locks (
    key character varying(255) NOT NULL,
    owner character varying(255) NOT NULL,
    expiration integer NOT NULL
);


ALTER TABLE public.cache_locks OWNER TO postgres;

--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: job_batches; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.job_batches (
    id character varying(255) NOT NULL,
    name character varying(255) NOT NULL,
    total_jobs integer NOT NULL,
    pending_jobs integer NOT NULL,
    failed_jobs integer NOT NULL,
    failed_job_ids text NOT NULL,
    options text,
    cancelled_at integer,
    created_at integer NOT NULL,
    finished_at integer
);


ALTER TABLE public.job_batches OWNER TO postgres;

--
-- Name: jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.jobs (
    id bigint NOT NULL,
    queue character varying(255) NOT NULL,
    payload text NOT NULL,
    attempts smallint NOT NULL,
    reserved_at integer,
    available_at integer NOT NULL,
    created_at integer NOT NULL
);


ALTER TABLE public.jobs OWNER TO postgres;

--
-- Name: jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.jobs_id_seq OWNER TO postgres;

--
-- Name: jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.jobs_id_seq OWNED BY public.jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: sessions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sessions (
    id character varying(255) NOT NULL,
    user_id bigint,
    ip_address character varying(45),
    user_agent text,
    payload text NOT NULL,
    last_activity integer NOT NULL
);


ALTER TABLE public.sessions OWNER TO postgres;

--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jobs ALTER COLUMN id SET DEFAULT nextval('public.jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: cache; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.cache (key, value, expiration) FROM stdin;
\.


--
-- Data for Name: cache_locks; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.cache_locks (key, owner, expiration) FROM stdin;
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: job_batches; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.job_batches (id, name, total_jobs, pending_jobs, failed_jobs, failed_job_ids, options, cancelled_at, created_at, finished_at) FROM stdin;
\.


--
-- Data for Name: jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.jobs (id, queue, payload, attempts, reserved_at, available_at, created_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	0001_01_01_000000_create_users_table	1
2	0001_01_01_000001_create_cache_table	1
3	0001_01_01_000002_create_jobs_table	1
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: sessions; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.sessions (id, user_id, ip_address, user_agent, payload, last_activity) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 3, true);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: cache_locks cache_locks_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cache_locks
    ADD CONSTRAINT cache_locks_pkey PRIMARY KEY (key);


--
-- Name: cache cache_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.cache
    ADD CONSTRAINT cache_pkey PRIMARY KEY (key);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: job_batches job_batches_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.job_batches
    ADD CONSTRAINT job_batches_pkey PRIMARY KEY (id);


--
-- Name: jobs jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jobs
    ADD CONSTRAINT jobs_pkey PRIMARY KEY (id);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: sessions sessions_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sessions
    ADD CONSTRAINT sessions_pkey PRIMARY KEY (id);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: jobs_queue_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX jobs_queue_index ON public.jobs USING btree (queue);


--
-- Name: sessions_last_activity_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX sessions_last_activity_index ON public.sessions USING btree (last_activity);


--
-- Name: sessions_user_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX sessions_user_id_index ON public.sessions USING btree (user_id);


--
-- PostgreSQL database dump complete
--

--
-- Database "mydb" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: mydb; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE mydb WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE mydb OWNER TO postgres;

\connect mydb

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "newblog" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: newblog; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE newblog WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE newblog OWNER TO postgres;

\connect newblog

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: articles; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.articles (
    id bigint NOT NULL,
    titre character varying(255) NOT NULL,
    contenu text NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone,
    author_id bigint
);


ALTER TABLE public.articles OWNER TO postgres;

--
-- Name: articles_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.articles_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.articles_id_seq OWNER TO postgres;

--
-- Name: articles_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.articles_id_seq OWNED BY public.articles.id;


--
-- Name: authors; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.authors (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    bio text,
    age integer,
    email character varying(255),
    phone character varying(255),
    photo character varying(255),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.authors OWNER TO postgres;

--
-- Name: authors_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.authors_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.authors_id_seq OWNER TO postgres;

--
-- Name: authors_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.authors_id_seq OWNED BY public.authors.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_reset_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_reset_tokens (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_reset_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    expires_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: articles id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.articles ALTER COLUMN id SET DEFAULT nextval('public.articles_id_seq'::regclass);


--
-- Name: authors id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.authors ALTER COLUMN id SET DEFAULT nextval('public.authors_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: articles; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.articles (id, titre, contenu, created_at, updated_at, author_id) FROM stdin;
1	Fugit fuga voluptatem hic occaecati dolorem culpa illo.	Dolorem omnis molestias nemo omnis distinctio aut ipsa temporibus. Fuga ea mollitia necessitatibus atque dolorem. Inventore nobis qui deserunt voluptatibus architecto facere nihil. Aut quia vel perferendis quasi aut.\n\nCommodi repellat est voluptatum in expedita molestias. Dolorum rerum animi sapiente sit recusandae. Voluptas et nulla rerum voluptate ipsa ipsum. Et dignissimos similique impedit dicta ullam tempore cum.\n\nIllo culpa neque ipsam asperiores molestiae. Omnis facere nostrum eveniet cum. Eius in adipisci accusantium et dolore. Inventore impedit atque labore illo.	2025-02-26 16:57:04	2025-02-26 16:57:04	1
2	Sed ut corporis vitae mollitia.	Ad eligendi sapiente qui molestias quia ut. Tempore ex natus reprehenderit sed.\n\nLibero et sit minima in non deserunt. Eos nemo corrupti rerum ut. Molestias consequatur debitis dicta illo et.\n\nConsectetur et vel voluptatem aperiam molestias unde. Non sunt distinctio quis eveniet minus blanditiis praesentium. Et tenetur nostrum esse consequatur aut porro. Officia dicta aut minima quae quaerat possimus.	2025-02-26 16:57:04	2025-02-26 16:57:04	2
3	Rem ut repellendus eius.	Libero temporibus qui quis. Voluptatem ipsam ut voluptatem delectus velit. Et ea nobis eum voluptas consequatur doloribus quaerat aliquid. Quia explicabo sed commodi expedita aut magnam.\n\nPariatur sit nihil dolores. Eos sit sit quasi pariatur illo. Cum aut autem unde quae nihil rerum et.\n\nQuo sunt voluptatem quo quae recusandae aut optio. Quia distinctio doloribus temporibus dolores exercitationem deserunt eligendi quis. Laudantium cupiditate mollitia sit facilis quia sed itaque eos. Ea nisi eligendi voluptatem omnis error non dolore.	2025-02-26 16:57:04	2025-02-26 16:57:04	3
4	Enim placeat ut est neque eos harum omnis.	Iste corporis dignissimos quod iste omnis. Est rem tempora maiores quasi ut optio et. Illo vero soluta provident. Ut consequatur animi saepe.\n\nImpedit id nemo rerum aut consequatur iste quas. Sed perferendis id dignissimos dolor reprehenderit quaerat. Ut enim iure quia quos similique enim. Minus officiis fuga ut non enim repellat animi.\n\nLaborum rerum officiis consectetur. Qui autem eaque similique qui est ipsa non ea.	2025-02-26 16:57:04	2025-02-26 16:57:04	4
5	Dolor et officiis et nulla.	Adipisci debitis accusantium laboriosam sed. Inventore commodi nemo ea autem voluptas sint amet. Aut sint error eum ut dolorum architecto deserunt est.\n\nAliquid odit quis eos dolore quia alias. Voluptas rem laborum rerum adipisci. Sapiente tenetur dolores nulla excepturi deleniti iusto dolorem. Non rem esse nihil error accusamus.\n\nSit sed nihil quasi reprehenderit eum sunt quae. Esse labore quo suscipit delectus temporibus id. Culpa qui ea cumque sint doloribus doloribus omnis.	2025-02-26 16:57:04	2025-02-26 16:57:04	5
6	Sit veritatis suscipit eveniet modi qui excepturi.	Repellendus tenetur ut aspernatur minus ratione. In et accusamus sapiente voluptatem eius et velit id. Neque placeat culpa explicabo doloremque deleniti mollitia. Qui dolorum nobis aut.\n\nMagni repellat totam aperiam vel sit sit consequatur fugit. Consequatur aliquam nihil temporibus libero porro. Deleniti laudantium vel atque dolores.\n\nExcepturi rerum quia iure voluptas molestiae amet qui aliquam. Officiis dolore nihil voluptatibus repudiandae. Sapiente optio voluptas voluptas delectus quia.	2025-02-26 16:57:04	2025-02-26 16:57:04	6
7	Aut eveniet nam occaecati et vero.	Impedit et laudantium id nemo ex. Enim quia recusandae veritatis accusamus assumenda. A voluptatem quia eum error optio et. Odit vero ut nisi voluptatem velit nihil sapiente.\n\nEt omnis omnis tenetur veritatis. Voluptatem minus mollitia amet quisquam. Eos et odio sunt quo aperiam.\n\nMaiores aspernatur repudiandae voluptas voluptatem corrupti accusantium. Culpa modi aut praesentium suscipit maiores. Consequatur unde facere laboriosam omnis voluptas sit. Exercitationem minima et voluptatibus itaque quo accusamus.	2025-02-26 16:57:04	2025-02-26 16:57:04	6
8	Delectus beatae eum omnis quaerat deleniti odit ullam.	Velit qui laudantium et illo aut sint. Beatae libero libero deleniti fugiat et nisi. Mollitia illum molestiae eius voluptates ea sapiente consequuntur.\n\nIste et sint dolorem consequatur facilis. Est animi dignissimos mollitia ut nihil sed et quis. Alias qui asperiores placeat possimus. Saepe mollitia doloremque maxime ut laboriosam magni minima dolore.\n\nQui cupiditate aut optio dolorem aliquam non nam. Ut mollitia molestiae vel quia laboriosam placeat repellendus. Voluptas est reiciendis aliquam voluptatibus facere quam tenetur voluptatem.	2025-02-26 16:57:04	2025-02-26 16:57:04	6
9	Nemo ipsam et veritatis sed repellat.	Vel aut dolor iste nemo. Quo qui accusantium facere. Omnis molestiae voluptate sed est omnis quae corporis. Temporibus voluptate et omnis ut.\n\nLaudantium quae praesentium nam earum fugit placeat eaque. Est molestias repellendus repellendus. Aut amet et eius sit exercitationem nobis.\n\nVoluptas eum sunt delectus placeat tenetur. Harum in sit ea praesentium est rerum id. Aut fuga et pariatur qui. Omnis doloribus qui nisi corrupti vitae debitis itaque. Voluptatum iste dolores id occaecati rem dolores doloremque.	2025-02-26 16:57:04	2025-02-26 16:57:04	7
10	Et autem fugiat ex voluptates sit dignissimos.	Voluptates rerum ab voluptatum rerum ipsum in. Natus dolorem mollitia eaque sapiente asperiores.\n\nReprehenderit voluptates doloribus minima non quam doloremque. Non sapiente molestiae corporis repellendus qui non. Maxime omnis earum autem dolores nihil expedita. Quos tenetur eveniet sed nemo error ut et.\n\nUt facilis aut laudantium sequi optio iusto. Culpa et fugiat at. Tempora eveniet et eos officia velit repellat. Nihil dolorem voluptatem et dolores ex accusantium aut.	2025-02-26 16:57:04	2025-02-26 16:57:04	7
11	Qui aut magnam nihil repellat et quia nihil.	Eos consequatur a voluptate amet at. Dolores ullam dolores quas qui aut architecto iste. Dolorem ab et autem impedit omnis autem error.\n\nDelectus et praesentium architecto a architecto. Corrupti esse iste reiciendis temporibus vero ipsum. Aperiam id officia sequi maiores dolores. Excepturi sit aperiam porro eligendi. Cum repudiandae maxime qui quisquam ratione.\n\nAut alias assumenda consequatur exercitationem. Praesentium mollitia dolorem libero quod corporis quasi officiis.	2025-02-26 16:57:04	2025-02-26 16:57:04	7
12	Ad repudiandae iste qui harum rerum ut.	Eum fuga dolorem deserunt at nam enim sint. Excepturi nemo sapiente nostrum vel. Eum minima aut accusamus quas consequuntur et corrupti.\n\nNumquam ut distinctio necessitatibus. Facilis itaque est molestiae impedit. Quisquam inventore repellendus ad fugit. Quia explicabo quia non.\n\nAccusamus ipsam libero accusamus cumque eaque blanditiis veniam. Quod eligendi occaecati enim.	2025-02-26 16:57:04	2025-02-26 16:57:04	8
13	Qui et maxime reiciendis magni nostrum.	Minima ut eos cumque asperiores fuga accusantium. Fugiat eum rerum modi sunt incidunt perspiciatis. Voluptatibus laborum et aliquam aut officiis delectus. Voluptatem dolorum nesciunt tenetur reiciendis perspiciatis qui.\n\nEos ut labore ab quidem quo aliquam. Ipsa doloribus omnis nulla aut ipsum ut eos. Maiores aperiam quis perspiciatis.\n\nEa reiciendis similique odio sint est quis. Numquam nulla cumque atque voluptatem temporibus veritatis voluptatem.	2025-02-26 16:57:04	2025-02-26 16:57:04	8
14	Libero veritatis omnis id quo.	Deleniti sit quam repudiandae. Vitae maxime sint minima asperiores ipsa ducimus fugit veniam. Optio aut voluptatem laborum error ipsum minus.\n\nPlaceat corporis voluptatem voluptatem a in. Dolorum vel ipsa rerum maxime quo. In et est id deleniti voluptates. Quia sunt fugit quia amet deleniti atque facilis.\n\nMagnam laboriosam repudiandae similique nulla et. Temporibus dignissimos neque iste delectus necessitatibus. Enim sapiente sed tenetur incidunt repellat. Suscipit repellat rerum officiis est dicta itaque vitae sunt. Voluptates molestias modi voluptatem modi.	2025-02-26 16:57:04	2025-02-26 16:57:04	8
15	At cupiditate sit ea id est omnis eos.	Suscipit corrupti temporibus quam quia. Quaerat non blanditiis officiis aut minima dolores. Voluptate inventore non voluptatum quidem. Voluptatem cum eum dolores distinctio ex commodi.\n\nAmet porro assumenda voluptatem reprehenderit. Fugiat culpa esse tenetur odit incidunt dolorem laborum distinctio. Dolore tenetur et autem enim recusandae ea. Ut cupiditate in ut illo qui iste.\n\nEst quia earum minus sed. Omnis cum ut doloremque aliquid voluptatem unde. Vitae natus nam ut inventore.	2025-02-26 16:57:04	2025-02-26 16:57:04	9
16	Officia et sed saepe libero reprehenderit facere.	Quos porro repellendus voluptas doloribus non. Distinctio delectus esse inventore et. Rerum corporis aperiam quis est commodi dignissimos est. Necessitatibus nobis dicta aut et ut ullam delectus.\n\nVoluptatibus sit ad praesentium molestias. Deleniti est odit repudiandae qui architecto corporis. Necessitatibus dolores molestias rem dicta quisquam. Dolorum maiores magni quas vel tenetur vero.\n\nEt et non est nesciunt neque reiciendis officia. Maiores dolor sint cumque ut consectetur ullam. Quo quod aliquam consequatur quasi consectetur.	2025-02-26 16:57:04	2025-02-26 16:57:04	9
17	Quo asperiores odit magnam voluptas commodi autem est.	Quia in dolores vitae qui sint. Quia voluptatibus et voluptas. Voluptatem numquam ad officiis beatae quam nostrum repudiandae.\n\nEt at corporis voluptatum est aspernatur. Qui placeat optio ut officiis cumque. Veniam voluptas laborum eos.\n\nEt officiis in et nam ab non et. Quis voluptas accusantium quis ut excepturi et iure et. Ullam voluptatem rerum ut. Dolores neque consequatur neque assumenda et quas.	2025-02-26 16:57:04	2025-02-26 16:57:04	9
18	Perferendis ut dolores voluptates quos nostrum necessitatibus.	Et laboriosam ad a sint enim quaerat. Et quod recusandae dignissimos sapiente eos commodi odit delectus. Fugit est molestiae debitis distinctio quia porro.\n\nPerspiciatis numquam delectus possimus ipsa esse qui. Et perspiciatis dolorum ipsam voluptatem esse magnam. Ullam voluptate quia dolores sit autem. Voluptas tempora omnis quis delectus. Dicta commodi hic cupiditate voluptatem.\n\nDelectus voluptatum et voluptatem. Officiis omnis qui est provident sint et assumenda.	2025-02-26 16:57:04	2025-02-26 16:57:04	10
19	Saepe sapiente id voluptas beatae quis rerum.	Et velit dolores minima nemo. Sapiente dolores alias possimus. Error quasi similique sed qui. Laborum inventore quis ratione quisquam sint.\n\nUt et sit vitae reprehenderit voluptatem nihil debitis. Neque ut voluptatem est consequatur consequuntur harum qui vitae. Molestiae molestiae aut porro nobis saepe et ut.\n\nAliquid ipsam quia dicta et. Pariatur explicabo fugiat eius ut. Omnis saepe quia animi quibusdam. Ipsum aut quia facere rerum.	2025-02-26 16:57:04	2025-02-26 16:57:04	10
20	Qui ducimus dolorem fugit ut.	Et commodi aut velit voluptate et rerum. Illum rerum accusantium atque fuga laudantium doloribus. Omnis veritatis laboriosam id quisquam facere iusto mollitia doloremque. Perferendis quae aut dolorum perferendis dolores.\n\nReiciendis ex unde illum quisquam nam. Aut nemo magni eum quae et similique quo ut. Ut tempore non sint quo pariatur quos. Sequi quaerat necessitatibus rerum culpa. A soluta consectetur ut totam iste.\n\nVoluptates quidem accusamus nisi rerum excepturi sunt ea. Commodi nisi esse libero officia tenetur quisquam. Adipisci ab vel sed itaque eius sequi. Illo blanditiis id aut debitis ipsa similique.	2025-02-26 16:57:04	2025-02-26 16:57:04	10
21	Recusandae quia veritatis ut similique.	Neque neque quae aliquam minima sit. Magni voluptatem voluptatibus veritatis qui similique voluptatem aut. Tempore omnis animi earum aut nihil. Aut et nihil ea facere.\n\nNumquam est ut perspiciatis quam non suscipit. Rerum qui voluptatibus non quos eaque. Magnam quam fugiat architecto repellendus quis et.\n\nOfficiis commodi vero veniam repudiandae quos consequuntur non. Laudantium tempora tempora laborum aut sed aut. Quia quaerat et omnis amet repellendus occaecati qui.	2025-02-26 16:57:04	2025-02-26 16:57:04	11
22	Provident reiciendis molestiae nisi id dolorem.	Quia aut laboriosam quo ratione asperiores aperiam. Doloribus qui quod id expedita nisi alias. Corrupti consequuntur commodi dolorum qui ipsam quam. Commodi sapiente dolor vel nihil.\n\nRerum eum explicabo accusantium eveniet. Reprehenderit aut rerum vel et officiis. Consequuntur iste nihil laborum nulla sunt.\n\nUt exercitationem tenetur consectetur optio. Maiores consequatur sunt est molestiae. Velit consectetur cum quia omnis. Quidem sunt magnam nisi consequatur non dolore reprehenderit.	2025-02-26 16:57:04	2025-02-26 16:57:04	11
23	Velit voluptatem voluptate beatae impedit molestiae est.	Sed fuga et aut placeat debitis esse. Sed omnis repudiandae quas beatae libero. Quo pariatur eum debitis similique.\n\nVoluptas odio labore enim aut. Repellat impedit repellat qui qui doloremque magni inventore. Et vel quia perspiciatis vitae similique dolores.\n\nNihil non possimus molestiae itaque hic voluptatem. Ut quam et quis sunt. Voluptatem cumque consequatur nisi recusandae.	2025-02-26 16:57:04	2025-02-26 16:57:04	11
24	Ut earum ipsum cumque est qui iste.	Voluptatum temporibus eius voluptatem dolores id expedita. Quas vitae non totam autem sed maiores labore. Consequatur voluptatem nulla maiores sequi dolorum dolorum. Quae et exercitationem sint incidunt.\n\nQuos sint assumenda aut consequuntur. Aliquam fugiat suscipit et molestias vel. Maiores ad repudiandae in corrupti fuga vero labore. Dolor omnis ut et dignissimos aspernatur.\n\nSit ab quod nihil sed hic deserunt. Occaecati nulla libero consequatur autem dolorem vitae quidem. Exercitationem qui laudantium quisquam qui. Facilis et et excepturi.	2025-02-26 16:57:04	2025-02-26 16:57:04	12
25	Consequuntur est nulla non error ut est.	Laudantium consequatur recusandae porro et eaque qui. Corrupti reiciendis voluptatem necessitatibus. Est fugit sed sunt corrupti sequi vitae similique. Voluptatem enim sit omnis qui eius culpa illo sit.\n\nModi consectetur quia quo sint ea. Ex sint non repudiandae nisi. Velit pariatur magnam cumque asperiores qui et. Nam numquam harum voluptatibus quas.\n\nTenetur molestiae eveniet aut iusto quia omnis. Quas porro temporibus ut enim. Rerum fugit et nihil et.	2025-02-26 16:57:04	2025-02-26 16:57:04	12
26	Alias voluptatibus ea quaerat minima dignissimos.	Repellendus sint nobis non consequatur neque qui. Vel ut et officia possimus. Labore ut maiores tempora animi quis.\n\nIn iusto sunt consequuntur nam. Consequatur quibusdam voluptatem praesentium unde reiciendis quis doloribus. Voluptatibus earum eaque autem quasi repellat ut est iure.\n\nEt adipisci quidem adipisci consequuntur accusantium et. Modi quasi repellat libero deleniti iusto doloribus. Aut ipsa soluta inventore.	2025-02-26 16:57:04	2025-02-26 16:57:04	12
27	Adipisci quibusdam cumque vero dolorem neque modi repellendus aut.	Nesciunt maxime eaque omnis numquam et. Voluptate aut molestiae illo inventore enim dicta aperiam. Vitae quas eum hic non. Reprehenderit qui sint repellendus reprehenderit dolorem.\n\nAsperiores minima quis voluptas eum eius earum. Facilis sequi impedit tenetur reiciendis perspiciatis consequatur ipsam.\n\nEligendi quo necessitatibus et. Vel recusandae sunt in modi. Odio odio ut assumenda mollitia modi illum. Repellendus quo vel veniam.	2025-02-26 16:57:05	2025-02-26 16:57:05	13
28	Et molestias atque voluptate necessitatibus et.	Consequuntur beatae aspernatur fuga sit voluptas velit. Voluptate dolorem eius perspiciatis nam excepturi sapiente inventore veniam. Aliquam ut fugiat odit quia voluptate quos quod minima. Nobis aut neque nisi laboriosam sed culpa omnis.\n\nUt totam accusamus sed quas et blanditiis tempora. Repellendus sed natus cum quia nisi animi expedita. Corrupti dolores dolores quasi dicta a delectus.\n\nEt dolorum architecto aperiam dicta in harum dolores. Odit excepturi odit error debitis. Officia consequatur at consequatur nostrum eaque ducimus. Aut nulla numquam nihil vero soluta.	2025-02-26 16:57:05	2025-02-26 16:57:05	13
29	Sed consequatur ea ullam distinctio possimus.	Quasi id est et voluptas fuga repellat. Optio non sit autem qui eos. Accusamus corporis aperiam non quasi.\n\nOccaecati ullam est cum soluta. Earum voluptate enim in impedit adipisci dolore. Porro in assumenda ab consectetur harum consectetur beatae ex.\n\nUllam quisquam placeat ad temporibus. Quaerat consectetur quod enim qui vel non repellat. Voluptates architecto aut quam dolores aut.	2025-02-26 16:57:05	2025-02-26 16:57:05	13
30	Quia consequatur consequatur qui aperiam quisquam autem officia.	Blanditiis consequatur dolor enim et. Magni neque quibusdam consequatur et. Ad ea ut velit consequuntur. Est autem tenetur rerum quis debitis et.\n\nUt sapiente tenetur et earum et architecto et. Rerum tempora dolorem recusandae tempora. Sunt qui et cumque temporibus qui est. Voluptas et placeat sapiente quod eos aspernatur ut.\n\nEsse eos at ea animi. Commodi exercitationem repellat animi iure vel officia earum. Et ad quia est et deleniti. Impedit quia aut sit quis non.	2025-02-26 16:57:05	2025-02-26 16:57:05	14
31	Recusandae unde ut voluptatum placeat.	Est voluptate aut rerum delectus architecto. Dignissimos animi autem eum quia voluptate delectus in. Libero similique qui quidem eos. Nobis quasi blanditiis modi molestiae consequatur ut.\n\nImpedit modi cupiditate qui consequatur ipsum dicta. Repellat perferendis quo delectus et. Ea laborum vero eos ad occaecati aut velit ipsam.\n\nEveniet ducimus dolorem nostrum exercitationem reiciendis. Ut praesentium omnis dolorum omnis. Sunt ex non et aut.	2025-02-26 16:57:05	2025-02-26 16:57:05	14
32	Natus quis dignissimos qui.	Dolorem incidunt dolorem eum ut est autem nam. Veritatis ex molestiae accusamus suscipit sed. Est corporis dolorum et. Facere necessitatibus blanditiis mollitia rerum modi esse.\n\nEt omnis id ut ea. Veniam modi et sint consectetur aut quo beatae et.\n\nOptio voluptatem nobis consequatur commodi molestiae quia magni voluptatem. Quibusdam sed necessitatibus est natus voluptates quidem quis magnam. Molestiae maiores assumenda est commodi praesentium blanditiis.	2025-02-26 16:57:05	2025-02-26 16:57:05	14
33	Ipsum explicabo possimus consequatur unde saepe sed quaerat temporibus.	Accusantium expedita illum et corrupti nostrum minima. Nihil laboriosam tempora architecto. Quibusdam quo voluptas id reiciendis quas optio. Voluptatum laudantium ea accusantium et et amet.\n\nNeque incidunt magnam quod laudantium est quo consequatur voluptatem. Accusamus consequatur dolorum repudiandae et. Rem alias expedita nemo amet fuga eos.\n\nEt molestias aliquam eos illum illum rerum doloribus. Inventore autem at qui. Ea ut odio quidem rerum dolorem eligendi tempore.	2025-02-26 16:57:05	2025-02-26 16:57:05	15
34	Autem repudiandae repudiandae debitis accusantium.	Aperiam enim at molestiae perferendis maiores unde magnam qui. Corporis sit et sint pariatur aliquam. Fuga ex eos ab nihil et sed. Facere eum beatae minima eveniet libero dolorem accusantium beatae.\n\nTempora est est quia animi rem. Aut aut consequatur eum pariatur quia blanditiis labore consequuntur.\n\nFacilis occaecati nemo in ipsa optio consectetur. Recusandae ratione aut aut quo et labore doloremque. Neque placeat consectetur repellat enim ipsa quam. Dolorem deserunt similique id esse eius.	2025-02-26 16:57:05	2025-02-26 16:57:05	15
35	Exercitationem vero esse ea et.	Velit aut omnis vitae pariatur quibusdam enim ex molestiae. Est ut quis vero ducimus amet. Mollitia corrupti aut odio quam modi itaque inventore eligendi. Qui illo error officiis et.\n\nPraesentium atque excepturi et aut. Et corporis nulla eos fugit voluptas. Illum ex non veritatis ut quam ducimus error similique.\n\nDolorem tempore in harum et asperiores quibusdam aut culpa. Nobis occaecati consectetur ad fugit.	2025-02-26 16:57:05	2025-02-26 16:57:05	15
36	Textes fondamentaux relatifs à la sécurité des journalistes	Aller au contenu principal\r\nAccueil\r\nMain navigation\r\nShareforward\r\nAccès rapide : UNESCO action in UkraineWorld Heritage\r\nFil d'Ariane\r\nSécurité des journalistes\r\nSafety of Journalists\r\nSécurité des journalistes\r\nchevron_left\r\nAccueil\r\nPlan d'action des Nations Unies\r\nSécurité des femmes journalistes\r\nIndicateurs\r\nObservatoire des journalistes assassinés\r\nRapport de la Directrice générale\r\nchevron_right\r\nTextes fondamentaux relatifs à la sécurité des journalistes\r\nDernière mise à jour2 juin 2023\r\nListe non exhaustive de textes, déclarations, décisions, résolutions et conventions relatifs aux droits de l’homme et à la sécurité des journalistes.\r\n\r\nLégislation internationale en matière de droits de l’homme\r\nONU - Déclaration universelle des droits de l’homme (1948)\r\nHCDH - Pacte international relatif aux droits civils et politiques (PIDCP) (1976)\r\nObservation générale n° 34 sur l’article 19 du PIDCP (2011)\r\nCommission des droits de l’homme des Nations Unies - Impunité. Résolution 2005/81 de la Commission des droits de l’homme (2005)\r\nConseil de sécurité des Nations Unies - Résolution S/RES/1738 (2006)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/21/12) sur la sécurité des journalistes (2012)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/68/163) sur la sécurité des journalistes et la question de l’impunité (2013)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/27/5) sur la sécurité des journalistes (2014)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/69/185) sur la sécurité des journalistes et la question de l’impunité (2014)\r\nRésolution du Conseil de sécurité des Nations Unies S/RES/2222 (2015)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/70/162) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/33/2) sur la sécurité des journalistes (2016)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/72/175) sur la sécurité des journalistes et le danger d’impunité (2017)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/74/157) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/45/18) sur la sécurité des journalistes (2020)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/75/101) - L’information au service de l’humanité (2020)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/47/16) sur la promotion, la protection et l’exercice des droits de l’homme sur Internet (2021)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/76/173) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nOffice des Nations Unies contre la drogue et le crime, Déclaration de Kyoto visant à faire progresser la prévention de la criminalité, la justice pénale et l’état de droit : vers la réalisation du Programme de développement durable à l’horizon 2030, adoptée lors du Quatorzième Congrès des Nations Unies pour la prévention du crime et la justice pénale (2021)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/50/15) sur la liberté d’opinion et d’expression (2022)\r\nRésolutions, décisions et déclarations de l’UNESCO sur la sécurité des journalistes\r\nDéclarations régionales\r\n\r\nDéclaration de Windhoek sur le développement d’une presse africaine indépendante et pluraliste (1991)\r\nDéclaration d’Alma-Ata sur la promotion de médias indépendants et pluralistes en Asie (1992)\r\nDéclaration de Santiago sur le développement des médias et la démocratie en Amérique latine et dans les Caraïbes (1994)\r\nDéclaration de Sana’a sur la promotion de médias arabes indépendants et pluralistes (1996)\r\nDéclaration de Sofia sur la promotion des médias européens indépendants et pluralistes (1997)\r\nRésolutions de la Conférence générale\r\n\r\nRésolution 4.3 de la Conférence générale de l’UNESCO sur la promotion de la liberté de la presse dans le monde (1991)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur le rôle et les missions du service public de radio et de télévision (1993)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur la promotion des médias indépendants et pluralistes (1995)\r\nRésolution 29 de l’UNESCO sur la condamnation de la violence contre les journalistes, adoptée lors de la 29e Conférence générale (1997)\r\nRésolution 34 de la Conférence générale de l’UNESCO sur la Déclaration de Sana’a (1997)\r\nRésolution 35 de la Conférence générale de l’UNESCO sur la Déclaration de Sofia (1997)\r\nRésolution 53 de l’UNESCO, adoptée lors de la 36eConférence générale (2011)\r\nRésolution 39 de l’UNESCO sur le renforcement de l’action de l’UNESCO dans la mise en œuvre du Plan d’action des Nations Unies, adoptée lors de la 39e Conférence générale (2017)\r\nRésolution 52 de l’UNESCO sur le Grand programme V - Communication et Information (2019)\r\nRésolution 41 de l’UNESCO sur la Déclaration de Windhoek+30 sur la Journée mondiale de la liberté de la presse 2021 (2021)\r\nDécisions du Conseil exécutif\r\n\r\nDécision du 196e Conseil exécutif de l’UNESCO (196 EX/31) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nDécision du 201e Conseil exécutif de l’UNESCO (201 EX/Décision 5.I.I) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 202e Conseil exécutif de l’UNESCO (202 EX/Décision 5 I.K) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 206e Conseil exécutif de l’UNESCO (206 EX/SR.7) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nDécision du 211e Conseil exécutif de l’UNESCO (211 EX/5.I.G) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nDécisions du Conseil intergouvernemental du PIDC\r\n\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2008)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2010)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2012)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2014)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2016)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2018)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2020)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2022)\r\nDéclarations de la Journée mondiale de la liberté de la presse\r\n\r\nDéclaration de Belgrade de l’UNESCO - Soutien aux médias dans les zones de conflit violent et dans les pays en transition (2004)\r\nDéclaration de Medellín de l’UNESCO - Sécurité des journalistes et lutte contre l’impunité (2007)\r\nDéclaration de Carthage de l’UNESCO sur la liberté de la presse et la sécurité des journalistes (2012)\r\nDéclaration de San José de l’UNESCO - Assurer la liberté d’expression dans tous les médias (2013)\r\nDéclaration de Paris de l’UNESCO sur liberté des médias pour un avenir meilleur (2014)\r\nDéclaration de Riga de l’UNESCO sur l’amélioration de l’information, l’égalité des sexes et la sécurité des médias à l’ère du numérique (2015)\r\nDéclaration de la Finlande sur l’accès à l’information et les libertés fondamentales (2016)\r\nDéclaration de Jakarta « Des esprits critiques pour des temps critiques : le rôle des médias dans la promotion de sociétés pacifiques, justes et inclusives » (2017)\r\nDéclaration d’Accra « Médias, justice et état de droit : les contrepoids du pouvoir » (2018)\r\nDéclaration d’Addis-Ababa « Journalisme et élections en temps de désinformation » (2019)\r\nDéclaration de Windhoek+30 (2021)\r\nDéclaration conjointe de l’ONU sur la sécurité des journalistes à l’occasion de la Journée mondiale de la liberté de la presse 2022 (2022)\r\nDéclaration conjointe des Présidents de l’ONU sur la liberté d’expression comme moteur de tous les autres droits de l’homme (2023)\r\nDéclarations conjointes des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression\r\n\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la promotion de liberté d’expression (1999)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la censure par l’assassinat et la diffamation (2000)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes de promotion de la liberté d’expression (2002)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression (2005)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes internationaux de promotion de la liberté d’expression (2006)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2010)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les atteintes à la liberté d’expression (2012-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la violence contre les journalistes et les professionnels des médias dans le contexte de manifestations (2013-3)\r\nCommuniqué de presse conjoint des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur une plus grande protection des journalistes couvrant les conflits (2014-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les réponses aux situations de conflit (2015)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2019)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les élections à l’ère du numérique (2020)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les politiciens et fonctionnaires et la liberté d’expression (2021)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et la justice entre les sexes (2022)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté des médias et la démocratie (2023)\r\nProcédure d’Examen périodique universel (incluant la contribution de l’UNESCO)\r\nL’Examen périodique universel (EPU) du Conseil des droits de l’homme est le mécanisme d’établissement de rapports des Nations Unies sur les droits de l’homme dans tous les États membres de l’ONU, auquel l’UNESCO contribue, notamment en ce qui concerne les droits fondamentaux que sont la liberté d’expression, la liberté d’information et la sécurité des journalistes. Il se réunit trois fois par an et donne l’occasion à chaque État membre de déclarer les mesures qu’il a prises pour améliorer les droits de l’homme au sein de ses frontières et remplir ses obligations.\r\n\r\n13e Session (2012) | 14e Session (2012) | 15e Session (2013) | 16e Session (2013) | 17e Session (2013)\r\n\r\n18e Session (2014) | 19e Session (2014) | 20e Session (2014) | 21e Session (2015) | 22e Session (2015)\r\n\r\n23e Session (2015) | 24e Session (2016) | 25e Session (2016) | 26e Session (2016) | 27e Session (2017)\r\n\r\n28e Session (2017) | 29e Session (2018) | 30e Session (2018) | 31e Session (2018) | 32e Session (2019)\r\n\r\n33e Session (2019) | 34e Session (2019) | 35e Session (2020) | 36e Session (2020) | 37e Session (2021)\r\n\r\n38e Session (2021) | 39e Session (2021) | 40e Session (2022) | 41e Session (2022) | 42e Session (2023)\r\n\r\nInstruments régionaux de législation en matière de droits de l’homme\r\nCharte africaine des droits de l’homme et des peuples (1981, en vigueur depuis 1986)\r\nConvention américaine relative aux droits de l’homme (1969, en vigueur depuis 1978)\r\nConvention européenne des droits de l’homme (1950, en vigueur depuis 1953)\r\nCharte arabe des droits de l’homme (2004, en vigueur depuis 2008)\r\nLois et mesures humanitaires\r\nConventions de Genève de 1949 et leurs Protocoles additionnels\r\nRésolution 2 de la 31e Conférence internationale du CICR sur le Plan d’action sur 4 ans (2011)\r\nMesures régionales spécifiques à la sécurité des journalistes\r\nDéclaration finale du Sommet mondial sur la société de l’information (SMSI) +10 (2013), Documents finaux de haut niveau du SMSI+10 (2014) et Résolution de l’Assemblée générale des Nations Unies (A/RES/70/125) sur le document final de la Réunion de haut niveau de l’Assemblée générale sur l’examen d’ensemble de la mise en œuvre des résultats du Sommet mondial sur la société de l’information (2016)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection et la promotion du journalisme d’investigation (2007)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2007)\r\nOrientations de l’UE relatives à la liberté d’expression en ligne et hors ligne (2014)\r\nConseil de l’Europe : Recommandation CM/Rec(2016)4 du Comité des ministres aux États membres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2016)\r\nDécision MC.DEC.3/18 du Conseil ministériel de l’OSCE sur la sécurité des journalistes (2018)\r\nDéclaration de principes en matière de liberté d’expression et d’accès à l’information en Afrique de la Commission africaine des droits de l’homme et des peuples (2019)\r\nRésolution de la Commission africaine des droits de l’homme et des peuples (ACHPR/Res.468 (LXVII) sur la sécurité des journalistes et les professionnels des médias en Afrique (2020)\r\nRésolution (2317) de l’Assemblée parlementaire du Conseil de l’Europe - Menaces sur la liberté des médias et la sécurité des journalistes en Europe (2020)\r\nConseil de l’Europe : Résolution de la Conférence des ministres responsables de la société des médias et de l’information sur la sécurité des journalistes (2021)\r\nDéclarations intergouvernementales\r\nConférence mondiale sur la liberté des médias : Engagement mondial en faveur de la liberté des médias (2019)\r\nEngagement de La Haye pour accroître la sécurité des journalistes (2020)\r\nDéclaration conjointe des Groupes d’amis sur la sécurité des journalistes sur la liberté de la presse (2021)\r\nDéclaration conjointe du Partenariat mondial d’action contre le harcèlement et les abus sexistes en ligne à l’occasion de la Journée mondiale de la liberté de la presse (2022)\r\nJournée mondiale de la liberté de la presse : Déclaration du Haut représentant au nom de l’Union européenne (2023)\r\nDéclarations des organisations non gouvernementales et de la société civile\r\nDéclaration de Londres des membres de la communauté mondiale des médias sur la sécurité des journalistes et la question de l’impunité (2012)\r\nRecommandations de la Conférence internationale de Varsovie sur la sécurité des journalistes (2013)\r\nPrincipes et pratiques de sécurité globale, un ensemble de normes de sécurité internationales destinées aux reporters indépendants en mission dangereuse, établies par une coalition de grandes sociétés de presse et d’organisations journalistiques (2015)\r\nDéclaration internationale sur la protection des journalistes, par l’Institut international de la presse, l’Institut international pour la sécurité de la presse, African Media Initiative et le Réseau de médias Al Jazeera (2016)\r\nDéclaration commune sur l’indépendance et la diversité des médias à l’ère du numérique (2018)\r\nPartenariat pour l’information et la démocratie, lancé par l’ONG Reporters sans frontières (2019)\r\nCoalition de la Fondation internationale pour les femmes dans les médias contre la violence en ligne (2021)\r\nDéclarations nationales résultant de consultations nationales sur le Plan d’action des Nations Unies\r\nDéclaration d’Islamabad sur la sécurité des journalistes et la question de l’impunité (2012)\r\nPlan d’action philippin sur la sécurité des journalistes (2019)\r\nPlan d’action national du Royaume-Uni de Grande-Bretagne et d’Irlande du Nord pour la sécurité des journalistes (2021)\r\nDécisions clés de la Cour internationale\r\nCarvajal Carvajal c. Columbia (2018). Cour interaméricaine des droits de l’homme\r\nHerzog et al. c. Brésil (2018). Cour interaméricaine des droits de l’homme\r\nJineth Bedoya et al. c. Colombie (2021) Cour interaméricaine des droits de l’homme\r\nShare\r\nCopied to clipboard\r\nThèmes liés\r\nInformation et communication \r\nUNESCO\r\nActualités\r\nCalendar of events\r\nIn brief\r\nNotre impact\r\nNotre Expertise\r\nPortail de données\r\nS'abonner à nos lettres d'information\r\nUNESCO Shop\r\nConditions d'utilisation\r\nUNESCO Logo et Patronage\r\nFAQ\r\nSignaler un cas de fraude, corruption ou autre manquement\r\nMessages Frauduleux\r\nPolitiques\r\nProtection des droits de l’homme (Procédure 104)\r\nPolitique de confidentialité\r\nAccès à l’information\r\nGestion environnementale\r\nFollow us\r\nFacebook\r\nThreads\r\nX\r\nYouTube\r\nInstagram\r\nLinkedIn\r\nNous utilisons des cookies sur ce site pour améliorer votre expérience de navigation. Pour en savoir plus sur notre manière d'utiliser les cookies, lisez notre politique de confidentialité.	2025-02-26 18:54:27	2025-02-26 18:54:27	7
37	Gestion environnementale	Aller au contenu principal\r\nAccueil\r\nMain navigation\r\nShareforward\r\nAccès rapide : UNESCO action in UkraineWorld Heritage\r\nFil d'Ariane\r\nSécurité des journalistes\r\nSafety of Journalists\r\nSécurité des journalistes\r\nchevron_left\r\nAccueil\r\nPlan d'action des Nations Unies\r\nSécurité des femmes journalistes\r\nIndicateurs\r\nObservatoire des journalistes assassinés\r\nRapport de la Directrice générale\r\nchevron_right\r\nTextes fondamentaux relatifs à la sécurité des journalistes\r\nDernière mise à jour2 juin 2023\r\nListe non exhaustive de textes, déclarations, décisions, résolutions et conventions relatifs aux droits de l’homme et à la sécurité des journalistes.\r\n\r\nLégislation internationale en matière de droits de l’homme\r\nONU - Déclaration universelle des droits de l’homme (1948)\r\nHCDH - Pacte international relatif aux droits civils et politiques (PIDCP) (1976)\r\nObservation générale n° 34 sur l’article 19 du PIDCP (2011)\r\nCommission des droits de l’homme des Nations Unies - Impunité. Résolution 2005/81 de la Commission des droits de l’homme (2005)\r\nConseil de sécurité des Nations Unies - Résolution S/RES/1738 (2006)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/21/12) sur la sécurité des journalistes (2012)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/68/163) sur la sécurité des journalistes et la question de l’impunité (2013)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/27/5) sur la sécurité des journalistes (2014)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/69/185) sur la sécurité des journalistes et la question de l’impunité (2014)\r\nRésolution du Conseil de sécurité des Nations Unies S/RES/2222 (2015)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/70/162) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/33/2) sur la sécurité des journalistes (2016)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/72/175) sur la sécurité des journalistes et le danger d’impunité (2017)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/74/157) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/45/18) sur la sécurité des journalistes (2020)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/75/101) - L’information au service de l’humanité (2020)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/47/16) sur la promotion, la protection et l’exercice des droits de l’homme sur Internet (2021)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/76/173) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nOffice des Nations Unies contre la drogue et le crime, Déclaration de Kyoto visant à faire progresser la prévention de la criminalité, la justice pénale et l’état de droit : vers la réalisation du Programme de développement durable à l’horizon 2030, adoptée lors du Quatorzième Congrès des Nations Unies pour la prévention du crime et la justice pénale (2021)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/50/15) sur la liberté d’opinion et d’expression (2022)\r\nRésolutions, décisions et déclarations de l’UNESCO sur la sécurité des journalistes\r\nDéclarations régionales\r\n\r\nDéclaration de Windhoek sur le développement d’une presse africaine indépendante et pluraliste (1991)\r\nDéclaration d’Alma-Ata sur la promotion de médias indépendants et pluralistes en Asie (1992)\r\nDéclaration de Santiago sur le développement des médias et la démocratie en Amérique latine et dans les Caraïbes (1994)\r\nDéclaration de Sana’a sur la promotion de médias arabes indépendants et pluralistes (1996)\r\nDéclaration de Sofia sur la promotion des médias européens indépendants et pluralistes (1997)\r\nRésolutions de la Conférence générale\r\n\r\nRésolution 4.3 de la Conférence générale de l’UNESCO sur la promotion de la liberté de la presse dans le monde (1991)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur le rôle et les missions du service public de radio et de télévision (1993)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur la promotion des médias indépendants et pluralistes (1995)\r\nRésolution 29 de l’UNESCO sur la condamnation de la violence contre les journalistes, adoptée lors de la 29e Conférence générale (1997)\r\nRésolution 34 de la Conférence générale de l’UNESCO sur la Déclaration de Sana’a (1997)\r\nRésolution 35 de la Conférence générale de l’UNESCO sur la Déclaration de Sofia (1997)\r\nRésolution 53 de l’UNESCO, adoptée lors de la 36eConférence générale (2011)\r\nRésolution 39 de l’UNESCO sur le renforcement de l’action de l’UNESCO dans la mise en œuvre du Plan d’action des Nations Unies, adoptée lors de la 39e Conférence générale (2017)\r\nRésolution 52 de l’UNESCO sur le Grand programme V - Communication et Information (2019)\r\nRésolution 41 de l’UNESCO sur la Déclaration de Windhoek+30 sur la Journée mondiale de la liberté de la presse 2021 (2021)\r\nDécisions du Conseil exécutif\r\n\r\nDécision du 196e Conseil exécutif de l’UNESCO (196 EX/31) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nDécision du 201e Conseil exécutif de l’UNESCO (201 EX/Décision 5.I.I) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 202e Conseil exécutif de l’UNESCO (202 EX/Décision 5 I.K) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 206e Conseil exécutif de l’UNESCO (206 EX/SR.7) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nDécision du 211e Conseil exécutif de l’UNESCO (211 EX/5.I.G) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nDécisions du Conseil intergouvernemental du PIDC\r\n\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2008)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2010)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2012)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2014)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2016)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2018)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2020)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2022)\r\nDéclarations de la Journée mondiale de la liberté de la presse\r\n\r\nDéclaration de Belgrade de l’UNESCO - Soutien aux médias dans les zones de conflit violent et dans les pays en transition (2004)\r\nDéclaration de Medellín de l’UNESCO - Sécurité des journalistes et lutte contre l’impunité (2007)\r\nDéclaration de Carthage de l’UNESCO sur la liberté de la presse et la sécurité des journalistes (2012)\r\nDéclaration de San José de l’UNESCO - Assurer la liberté d’expression dans tous les médias (2013)\r\nDéclaration de Paris de l’UNESCO sur liberté des médias pour un avenir meilleur (2014)\r\nDéclaration de Riga de l’UNESCO sur l’amélioration de l’information, l’égalité des sexes et la sécurité des médias à l’ère du numérique (2015)\r\nDéclaration de la Finlande sur l’accès à l’information et les libertés fondamentales (2016)\r\nDéclaration de Jakarta « Des esprits critiques pour des temps critiques : le rôle des médias dans la promotion de sociétés pacifiques, justes et inclusives » (2017)\r\nDéclaration d’Accra « Médias, justice et état de droit : les contrepoids du pouvoir » (2018)\r\nDéclaration d’Addis-Ababa « Journalisme et élections en temps de désinformation » (2019)\r\nDéclaration de Windhoek+30 (2021)\r\nDéclaration conjointe de l’ONU sur la sécurité des journalistes à l’occasion de la Journée mondiale de la liberté de la presse 2022 (2022)\r\nDéclaration conjointe des Présidents de l’ONU sur la liberté d’expression comme moteur de tous les autres droits de l’homme (2023)\r\nDéclarations conjointes des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression\r\n\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la promotion de liberté d’expression (1999)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la censure par l’assassinat et la diffamation (2000)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes de promotion de la liberté d’expression (2002)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression (2005)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes internationaux de promotion de la liberté d’expression (2006)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2010)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les atteintes à la liberté d’expression (2012-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la violence contre les journalistes et les professionnels des médias dans le contexte de manifestations (2013-3)\r\nCommuniqué de presse conjoint des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur une plus grande protection des journalistes couvrant les conflits (2014-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les réponses aux situations de conflit (2015)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2019)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les élections à l’ère du numérique (2020)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les politiciens et fonctionnaires et la liberté d’expression (2021)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et la justice entre les sexes (2022)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté des médias et la démocratie (2023)\r\nProcédure d’Examen périodique universel (incluant la contribution de l’UNESCO)\r\nL’Examen périodique universel (EPU) du Conseil des droits de l’homme est le mécanisme d’établissement de rapports des Nations Unies sur les droits de l’homme dans tous les États membres de l’ONU, auquel l’UNESCO contribue, notamment en ce qui concerne les droits fondamentaux que sont la liberté d’expression, la liberté d’information et la sécurité des journalistes. Il se réunit trois fois par an et donne l’occasion à chaque État membre de déclarer les mesures qu’il a prises pour améliorer les droits de l’homme au sein de ses frontières et remplir ses obligations.\r\n\r\n13e Session (2012) | 14e Session (2012) | 15e Session (2013) | 16e Session (2013) | 17e Session (2013)\r\n\r\n18e Session (2014) | 19e Session (2014) | 20e Session (2014) | 21e Session (2015) | 22e Session (2015)\r\n\r\n23e Session (2015) | 24e Session (2016) | 25e Session (2016) | 26e Session (2016) | 27e Session (2017)\r\n\r\n28e Session (2017) | 29e Session (2018) | 30e Session (2018) | 31e Session (2018) | 32e Session (2019)\r\n\r\n33e Session (2019) | 34e Session (2019) | 35e Session (2020) | 36e Session (2020) | 37e Session (2021)\r\n\r\n38e Session (2021) | 39e Session (2021) | 40e Session (2022) | 41e Session (2022) | 42e Session (2023)\r\n\r\nInstruments régionaux de législation en matière de droits de l’homme\r\nCharte africaine des droits de l’homme et des peuples (1981, en vigueur depuis 1986)\r\nConvention américaine relative aux droits de l’homme (1969, en vigueur depuis 1978)\r\nConvention européenne des droits de l’homme (1950, en vigueur depuis 1953)\r\nCharte arabe des droits de l’homme (2004, en vigueur depuis 2008)\r\nLois et mesures humanitaires\r\nConventions de Genève de 1949 et leurs Protocoles additionnels\r\nRésolution 2 de la 31e Conférence internationale du CICR sur le Plan d’action sur 4 ans (2011)\r\nMesures régionales spécifiques à la sécurité des journalistes\r\nDéclaration finale du Sommet mondial sur la société de l’information (SMSI) +10 (2013), Documents finaux de haut niveau du SMSI+10 (2014) et Résolution de l’Assemblée générale des Nations Unies (A/RES/70/125) sur le document final de la Réunion de haut niveau de l’Assemblée générale sur l’examen d’ensemble de la mise en œuvre des résultats du Sommet mondial sur la société de l’information (2016)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection et la promotion du journalisme d’investigation (2007)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2007)\r\nOrientations de l’UE relatives à la liberté d’expression en ligne et hors ligne (2014)\r\nConseil de l’Europe : Recommandation CM/Rec(2016)4 du Comité des ministres aux États membres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2016)\r\nDécision MC.DEC.3/18 du Conseil ministériel de l’OSCE sur la sécurité des journalistes (2018)\r\nDéclaration de principes en matière de liberté d’expression et d’accès à l’information en Afrique de la Commission africaine des droits de l’homme et des peuples (2019)\r\nRésolution de la Commission africaine des droits de l’homme et des peuples (ACHPR/Res.468 (LXVII) sur la sécurité des journalistes et les professionnels des médias en Afrique (2020)\r\nRésolution (2317) de l’Assemblée parlementaire du Conseil de l’Europe - Menaces sur la liberté des médias et la sécurité des journalistes en Europe (2020)\r\nConseil de l’Europe : Résolution de la Conférence des ministres responsables de la société des médias et de l’information sur la sécurité des journalistes (2021)\r\nDéclarations intergouvernementales\r\nConférence mondiale sur la liberté des médias : Engagement mondial en faveur de la liberté des médias (2019)\r\nEngagement de La Haye pour accroître la sécurité des journalistes (2020)\r\nDéclaration conjointe des Groupes d’amis sur la sécurité des journalistes sur la liberté de la presse (2021)\r\nDéclaration conjointe du Partenariat mondial d’action contre le harcèlement et les abus sexistes en ligne à l’occasion de la Journée mondiale de la liberté de la presse (2022)\r\nJournée mondiale de la liberté de la presse : Déclaration du Haut représentant au nom de l’Union européenne (2023)\r\nDéclarations des organisations non gouvernementales et de la société civile\r\nDéclaration de Londres des membres de la communauté mondiale des médias sur la sécurité des journalistes et la question de l’impunité (2012)\r\nRecommandations de la Conférence internationale de Varsovie sur la sécurité des journalistes (2013)\r\nPrincipes et pratiques de sécurité globale, un ensemble de normes de sécurité internationales destinées aux reporters indépendants en mission dangereuse, établies par une coalition de grandes sociétés de presse et d’organisations journalistiques (2015)\r\nDéclaration internationale sur la protection des journalistes, par l’Institut international de la presse, l’Institut international pour la sécurité de la presse, African Media Initiative et le Réseau de médias Al Jazeera (2016)\r\nDéclaration commune sur l’indépendance et la diversité des médias à l’ère du numérique (2018)\r\nPartenariat pour l’information et la démocratie, lancé par l’ONG Reporters sans frontières (2019)\r\nCoalition de la Fondation internationale pour les femmes dans les médias contre la violence en ligne (2021)\r\nDéclarations nationales résultant de consultations nationales sur le Plan d’action des Nations Unies\r\nDéclaration d’Islamabad sur la sécurité des journalistes et la question de l’impunité (2012)\r\nPlan d’action philippin sur la sécurité des journalistes (2019)\r\nPlan d’action national du Royaume-Uni de Grande-Bretagne et d’Irlande du Nord pour la sécurité des journalistes (2021)\r\nDécisions clés de la Cour internationale\r\nCarvajal Carvajal c. Columbia (2018). Cour interaméricaine des droits de l’homme\r\nHerzog et al. c. Brésil (2018). Cour interaméricaine des droits de l’homme\r\nJineth Bedoya et al. c. Colombie (2021) Cour interaméricaine des droits de l’homme\r\nShare\r\nCopied to clipboard\r\nThèmes liés\r\nInformation et communication \r\nUNESCO\r\nActualités\r\nCalendar of events\r\nIn brief\r\nNotre impact\r\nNotre Expertise\r\nPortail de données\r\nS'abonner à nos lettres d'information\r\nUNESCO Shop\r\nConditions d'utilisation\r\nUNESCO Logo et Patronage\r\nFAQ\r\nSignaler un cas de fraude, corruption ou autre manquement\r\nMessages Frauduleux\r\nPolitiques\r\nProtection des droits de l’homme (Procédure 104)\r\nPolitique de confidentialité\r\nAccès à l’information\r\nGestion environnementale\r\nFollow us\r\nFacebook\r\nThreads\r\nX\r\nYouTube\r\nInstagram\r\nLinkedIn\r\nNous utilisons des cookies sur ce site pour améliorer votre expérience de navigation. Pour en savoir plus sur notre manière d'utiliser les cookies, lisez notre politique de confidentialité.	2025-02-26 18:55:20	2025-02-26 18:55:20	6
38	Lois et mesures humanitaires	Aller au contenu principal\r\nAccueil\r\nMain navigation\r\nShareforward\r\nAccès rapide : UNESCO action in UkraineWorld Heritage\r\nFil d'Ariane\r\nSécurité des journalistes\r\nSafety of Journalists\r\nSécurité des journalistes\r\nchevron_left\r\nAccueil\r\nPlan d'action des Nations Unies\r\nSécurité des femmes journalistes\r\nIndicateurs\r\nObservatoire des journalistes assassinés\r\nRapport de la Directrice générale\r\nchevron_right\r\nTextes fondamentaux relatifs à la sécurité des journalistes\r\nDernière mise à jour2 juin 2023\r\nListe non exhaustive de textes, déclarations, décisions, résolutions et conventions relatifs aux droits de l’homme et à la sécurité des journalistes.\r\n\r\nLégislation internationale en matière de droits de l’homme\r\nONU - Déclaration universelle des droits de l’homme (1948)\r\nHCDH - Pacte international relatif aux droits civils et politiques (PIDCP) (1976)\r\nObservation générale n° 34 sur l’article 19 du PIDCP (2011)\r\nCommission des droits de l’homme des Nations Unies - Impunité. Résolution 2005/81 de la Commission des droits de l’homme (2005)\r\nConseil de sécurité des Nations Unies - Résolution S/RES/1738 (2006)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/21/12) sur la sécurité des journalistes (2012)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/68/163) sur la sécurité des journalistes et la question de l’impunité (2013)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/27/5) sur la sécurité des journalistes (2014)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/69/185) sur la sécurité des journalistes et la question de l’impunité (2014)\r\nRésolution du Conseil de sécurité des Nations Unies S/RES/2222 (2015)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/70/162) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/33/2) sur la sécurité des journalistes (2016)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/72/175) sur la sécurité des journalistes et le danger d’impunité (2017)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/74/157) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/45/18) sur la sécurité des journalistes (2020)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/75/101) - L’information au service de l’humanité (2020)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/47/16) sur la promotion, la protection et l’exercice des droits de l’homme sur Internet (2021)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/76/173) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nOffice des Nations Unies contre la drogue et le crime, Déclaration de Kyoto visant à faire progresser la prévention de la criminalité, la justice pénale et l’état de droit : vers la réalisation du Programme de développement durable à l’horizon 2030, adoptée lors du Quatorzième Congrès des Nations Unies pour la prévention du crime et la justice pénale (2021)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/50/15) sur la liberté d’opinion et d’expression (2022)\r\nRésolutions, décisions et déclarations de l’UNESCO sur la sécurité des journalistes\r\nDéclarations régionales\r\n\r\nDéclaration de Windhoek sur le développement d’une presse africaine indépendante et pluraliste (1991)\r\nDéclaration d’Alma-Ata sur la promotion de médias indépendants et pluralistes en Asie (1992)\r\nDéclaration de Santiago sur le développement des médias et la démocratie en Amérique latine et dans les Caraïbes (1994)\r\nDéclaration de Sana’a sur la promotion de médias arabes indépendants et pluralistes (1996)\r\nDéclaration de Sofia sur la promotion des médias européens indépendants et pluralistes (1997)\r\nRésolutions de la Conférence générale\r\n\r\nRésolution 4.3 de la Conférence générale de l’UNESCO sur la promotion de la liberté de la presse dans le monde (1991)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur le rôle et les missions du service public de radio et de télévision (1993)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur la promotion des médias indépendants et pluralistes (1995)\r\nRésolution 29 de l’UNESCO sur la condamnation de la violence contre les journalistes, adoptée lors de la 29e Conférence générale (1997)\r\nRésolution 34 de la Conférence générale de l’UNESCO sur la Déclaration de Sana’a (1997)\r\nRésolution 35 de la Conférence générale de l’UNESCO sur la Déclaration de Sofia (1997)\r\nRésolution 53 de l’UNESCO, adoptée lors de la 36eConférence générale (2011)\r\nRésolution 39 de l’UNESCO sur le renforcement de l’action de l’UNESCO dans la mise en œuvre du Plan d’action des Nations Unies, adoptée lors de la 39e Conférence générale (2017)\r\nRésolution 52 de l’UNESCO sur le Grand programme V - Communication et Information (2019)\r\nRésolution 41 de l’UNESCO sur la Déclaration de Windhoek+30 sur la Journée mondiale de la liberté de la presse 2021 (2021)\r\nDécisions du Conseil exécutif\r\n\r\nDécision du 196e Conseil exécutif de l’UNESCO (196 EX/31) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nDécision du 201e Conseil exécutif de l’UNESCO (201 EX/Décision 5.I.I) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 202e Conseil exécutif de l’UNESCO (202 EX/Décision 5 I.K) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 206e Conseil exécutif de l’UNESCO (206 EX/SR.7) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nDécision du 211e Conseil exécutif de l’UNESCO (211 EX/5.I.G) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nDécisions du Conseil intergouvernemental du PIDC\r\n\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2008)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2010)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2012)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2014)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2016)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2018)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2020)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2022)\r\nDéclarations de la Journée mondiale de la liberté de la presse\r\n\r\nDéclaration de Belgrade de l’UNESCO - Soutien aux médias dans les zones de conflit violent et dans les pays en transition (2004)\r\nDéclaration de Medellín de l’UNESCO - Sécurité des journalistes et lutte contre l’impunité (2007)\r\nDéclaration de Carthage de l’UNESCO sur la liberté de la presse et la sécurité des journalistes (2012)\r\nDéclaration de San José de l’UNESCO - Assurer la liberté d’expression dans tous les médias (2013)\r\nDéclaration de Paris de l’UNESCO sur liberté des médias pour un avenir meilleur (2014)\r\nDéclaration de Riga de l’UNESCO sur l’amélioration de l’information, l’égalité des sexes et la sécurité des médias à l’ère du numérique (2015)\r\nDéclaration de la Finlande sur l’accès à l’information et les libertés fondamentales (2016)\r\nDéclaration de Jakarta « Des esprits critiques pour des temps critiques : le rôle des médias dans la promotion de sociétés pacifiques, justes et inclusives » (2017)\r\nDéclaration d’Accra « Médias, justice et état de droit : les contrepoids du pouvoir » (2018)\r\nDéclaration d’Addis-Ababa « Journalisme et élections en temps de désinformation » (2019)\r\nDéclaration de Windhoek+30 (2021)\r\nDéclaration conjointe de l’ONU sur la sécurité des journalistes à l’occasion de la Journée mondiale de la liberté de la presse 2022 (2022)\r\nDéclaration conjointe des Présidents de l’ONU sur la liberté d’expression comme moteur de tous les autres droits de l’homme (2023)\r\nDéclarations conjointes des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression\r\n\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la promotion de liberté d’expression (1999)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la censure par l’assassinat et la diffamation (2000)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes de promotion de la liberté d’expression (2002)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression (2005)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes internationaux de promotion de la liberté d’expression (2006)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2010)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les atteintes à la liberté d’expression (2012-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la violence contre les journalistes et les professionnels des médias dans le contexte de manifestations (2013-3)\r\nCommuniqué de presse conjoint des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur une plus grande protection des journalistes couvrant les conflits (2014-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les réponses aux situations de conflit (2015)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2019)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les élections à l’ère du numérique (2020)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les politiciens et fonctionnaires et la liberté d’expression (2021)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et la justice entre les sexes (2022)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté des médias et la démocratie (2023)\r\nProcédure d’Examen périodique universel (incluant la contribution de l’UNESCO)\r\nL’Examen périodique universel (EPU) du Conseil des droits de l’homme est le mécanisme d’établissement de rapports des Nations Unies sur les droits de l’homme dans tous les États membres de l’ONU, auquel l’UNESCO contribue, notamment en ce qui concerne les droits fondamentaux que sont la liberté d’expression, la liberté d’information et la sécurité des journalistes. Il se réunit trois fois par an et donne l’occasion à chaque État membre de déclarer les mesures qu’il a prises pour améliorer les droits de l’homme au sein de ses frontières et remplir ses obligations.\r\n\r\n13e Session (2012) | 14e Session (2012) | 15e Session (2013) | 16e Session (2013) | 17e Session (2013)\r\n\r\n18e Session (2014) | 19e Session (2014) | 20e Session (2014) | 21e Session (2015) | 22e Session (2015)\r\n\r\n23e Session (2015) | 24e Session (2016) | 25e Session (2016) | 26e Session (2016) | 27e Session (2017)\r\n\r\n28e Session (2017) | 29e Session (2018) | 30e Session (2018) | 31e Session (2018) | 32e Session (2019)\r\n\r\n33e Session (2019) | 34e Session (2019) | 35e Session (2020) | 36e Session (2020) | 37e Session (2021)\r\n\r\n38e Session (2021) | 39e Session (2021) | 40e Session (2022) | 41e Session (2022) | 42e Session (2023)\r\n\r\nInstruments régionaux de législation en matière de droits de l’homme\r\nCharte africaine des droits de l’homme et des peuples (1981, en vigueur depuis 1986)\r\nConvention américaine relative aux droits de l’homme (1969, en vigueur depuis 1978)\r\nConvention européenne des droits de l’homme (1950, en vigueur depuis 1953)\r\nCharte arabe des droits de l’homme (2004, en vigueur depuis 2008)\r\nLois et mesures humanitaires\r\nConventions de Genève de 1949 et leurs Protocoles additionnels\r\nRésolution 2 de la 31e Conférence internationale du CICR sur le Plan d’action sur 4 ans (2011)\r\nMesures régionales spécifiques à la sécurité des journalistes\r\nDéclaration finale du Sommet mondial sur la société de l’information (SMSI) +10 (2013), Documents finaux de haut niveau du SMSI+10 (2014) et Résolution de l’Assemblée générale des Nations Unies (A/RES/70/125) sur le document final de la Réunion de haut niveau de l’Assemblée générale sur l’examen d’ensemble de la mise en œuvre des résultats du Sommet mondial sur la société de l’information (2016)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection et la promotion du journalisme d’investigation (2007)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2007)\r\nOrientations de l’UE relatives à la liberté d’expression en ligne et hors ligne (2014)\r\nConseil de l’Europe : Recommandation CM/Rec(2016)4 du Comité des ministres aux États membres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2016)\r\nDécision MC.DEC.3/18 du Conseil ministériel de l’OSCE sur la sécurité des journalistes (2018)\r\nDéclaration de principes en matière de liberté d’expression et d’accès à l’information en Afrique de la Commission africaine des droits de l’homme et des peuples (2019)\r\nRésolution de la Commission africaine des droits de l’homme et des peuples (ACHPR/Res.468 (LXVII) sur la sécurité des journalistes et les professionnels des médias en Afrique (2020)\r\nRésolution (2317) de l’Assemblée parlementaire du Conseil de l’Europe - Menaces sur la liberté des médias et la sécurité des journalistes en Europe (2020)\r\nConseil de l’Europe : Résolution de la Conférence des ministres responsables de la société des médias et de l’information sur la sécurité des journalistes (2021)\r\nDéclarations intergouvernementales\r\nConférence mondiale sur la liberté des médias : Engagement mondial en faveur de la liberté des médias (2019)\r\nEngagement de La Haye pour accroître la sécurité des journalistes (2020)\r\nDéclaration conjointe des Groupes d’amis sur la sécurité des journalistes sur la liberté de la presse (2021)\r\nDéclaration conjointe du Partenariat mondial d’action contre le harcèlement et les abus sexistes en ligne à l’occasion de la Journée mondiale de la liberté de la presse (2022)\r\nJournée mondiale de la liberté de la presse : Déclaration du Haut représentant au nom de l’Union européenne (2023)\r\nDéclarations des organisations non gouvernementales et de la société civile\r\nDéclaration de Londres des membres de la communauté mondiale des médias sur la sécurité des journalistes et la question de l’impunité (2012)\r\nRecommandations de la Conférence internationale de Varsovie sur la sécurité des journalistes (2013)\r\nPrincipes et pratiques de sécurité globale, un ensemble de normes de sécurité internationales destinées aux reporters indépendants en mission dangereuse, établies par une coalition de grandes sociétés de presse et d’organisations journalistiques (2015)\r\nDéclaration internationale sur la protection des journalistes, par l’Institut international de la presse, l’Institut international pour la sécurité de la presse, African Media Initiative et le Réseau de médias Al Jazeera (2016)\r\nDéclaration commune sur l’indépendance et la diversité des médias à l’ère du numérique (2018)\r\nPartenariat pour l’information et la démocratie, lancé par l’ONG Reporters sans frontières (2019)\r\nCoalition de la Fondation internationale pour les femmes dans les médias contre la violence en ligne (2021)\r\nDéclarations nationales résultant de consultations nationales sur le Plan d’action des Nations Unies\r\nDéclaration d’Islamabad sur la sécurité des journalistes et la question de l’impunité (2012)\r\nPlan d’action philippin sur la sécurité des journalistes (2019)\r\nPlan d’action national du Royaume-Uni de Grande-Bretagne et d’Irlande du Nord pour la sécurité des journalistes (2021)\r\nDécisions clés de la Cour internationale\r\nCarvajal Carvajal c. Columbia (2018). Cour interaméricaine des droits de l’homme\r\nHerzog et al. c. Brésil (2018). Cour interaméricaine des droits de l’homme\r\nJineth Bedoya et al. c. Colombie (2021) Cour interaméricaine des droits de l’homme\r\nShare\r\nCopied to clipboard\r\nThèmes liés\r\nInformation et communication \r\nUNESCO\r\nActualités\r\nCalendar of events\r\nIn brief\r\nNotre impact\r\nNotre Expertise\r\nPortail de données\r\nS'abonner à nos lettres d'information\r\nUNESCO Shop\r\nConditions d'utilisation\r\nUNESCO Logo et Patronage\r\nFAQ\r\nSignaler un cas de fraude, corruption ou autre manquement\r\nMessages Frauduleux\r\nPolitiques\r\nProtection des droits de l’homme (Procédure 104)\r\nPolitique de confidentialité\r\nAccès à l’information\r\nGestion environnementale\r\nFollow us\r\nFacebook\r\nThreads\r\nX\r\nYouTube\r\nInstagram\r\nLinkedIn\r\nNous utilisons des cookies sur ce site pour améliorer votre expérience de navigation. Pour en savoir plus sur notre manière d'utiliser les cookies, lisez notre politique de confidentialité.	2025-02-26 18:56:16	2025-02-26 18:56:16	8
39	Plan d’action philippin sur la sécurité des journalistes (2019)	Aller au contenu principal\r\nAccueil\r\nMain navigation\r\nShareforward\r\nAccès rapide : UNESCO action in UkraineWorld Heritage\r\nFil d'Ariane\r\nSécurité des journalistes\r\nSafety of Journalists\r\nSécurité des journalistes\r\nchevron_left\r\nAccueil\r\nPlan d'action des Nations Unies\r\nSécurité des femmes journalistes\r\nIndicateurs\r\nObservatoire des journalistes assassinés\r\nRapport de la Directrice générale\r\nchevron_right\r\nTextes fondamentaux relatifs à la sécurité des journalistes\r\nDernière mise à jour2 juin 2023\r\nListe non exhaustive de textes, déclarations, décisions, résolutions et conventions relatifs aux droits de l’homme et à la sécurité des journalistes.\r\n\r\nLégislation internationale en matière de droits de l’homme\r\nONU - Déclaration universelle des droits de l’homme (1948)\r\nHCDH - Pacte international relatif aux droits civils et politiques (PIDCP) (1976)\r\nObservation générale n° 34 sur l’article 19 du PIDCP (2011)\r\nCommission des droits de l’homme des Nations Unies - Impunité. Résolution 2005/81 de la Commission des droits de l’homme (2005)\r\nConseil de sécurité des Nations Unies - Résolution S/RES/1738 (2006)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/21/12) sur la sécurité des journalistes (2012)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/68/163) sur la sécurité des journalistes et la question de l’impunité (2013)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/27/5) sur la sécurité des journalistes (2014)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/69/185) sur la sécurité des journalistes et la question de l’impunité (2014)\r\nRésolution du Conseil de sécurité des Nations Unies S/RES/2222 (2015)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/70/162) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/33/2) sur la sécurité des journalistes (2016)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/72/175) sur la sécurité des journalistes et le danger d’impunité (2017)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/74/157) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/45/18) sur la sécurité des journalistes (2020)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/75/101) - L’information au service de l’humanité (2020)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/47/16) sur la promotion, la protection et l’exercice des droits de l’homme sur Internet (2021)\r\nRésolution de l’Assemblée générale des Nations Unies (A/RES/76/173) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nOffice des Nations Unies contre la drogue et le crime, Déclaration de Kyoto visant à faire progresser la prévention de la criminalité, la justice pénale et l’état de droit : vers la réalisation du Programme de développement durable à l’horizon 2030, adoptée lors du Quatorzième Congrès des Nations Unies pour la prévention du crime et la justice pénale (2021)\r\nRésolution du Conseil des droits de l’homme (A/HRC/RES/50/15) sur la liberté d’opinion et d’expression (2022)\r\nRésolutions, décisions et déclarations de l’UNESCO sur la sécurité des journalistes\r\nDéclarations régionales\r\n\r\nDéclaration de Windhoek sur le développement d’une presse africaine indépendante et pluraliste (1991)\r\nDéclaration d’Alma-Ata sur la promotion de médias indépendants et pluralistes en Asie (1992)\r\nDéclaration de Santiago sur le développement des médias et la démocratie en Amérique latine et dans les Caraïbes (1994)\r\nDéclaration de Sana’a sur la promotion de médias arabes indépendants et pluralistes (1996)\r\nDéclaration de Sofia sur la promotion des médias européens indépendants et pluralistes (1997)\r\nRésolutions de la Conférence générale\r\n\r\nRésolution 4.3 de la Conférence générale de l’UNESCO sur la promotion de la liberté de la presse dans le monde (1991)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur le rôle et les missions du service public de radio et de télévision (1993)\r\nRésolution 4.6 de la Conférence générale de l’UNESCO sur la promotion des médias indépendants et pluralistes (1995)\r\nRésolution 29 de l’UNESCO sur la condamnation de la violence contre les journalistes, adoptée lors de la 29e Conférence générale (1997)\r\nRésolution 34 de la Conférence générale de l’UNESCO sur la Déclaration de Sana’a (1997)\r\nRésolution 35 de la Conférence générale de l’UNESCO sur la Déclaration de Sofia (1997)\r\nRésolution 53 de l’UNESCO, adoptée lors de la 36eConférence générale (2011)\r\nRésolution 39 de l’UNESCO sur le renforcement de l’action de l’UNESCO dans la mise en œuvre du Plan d’action des Nations Unies, adoptée lors de la 39e Conférence générale (2017)\r\nRésolution 52 de l’UNESCO sur le Grand programme V - Communication et Information (2019)\r\nRésolution 41 de l’UNESCO sur la Déclaration de Windhoek+30 sur la Journée mondiale de la liberté de la presse 2021 (2021)\r\nDécisions du Conseil exécutif\r\n\r\nDécision du 196e Conseil exécutif de l’UNESCO (196 EX/31) sur la sécurité des journalistes et la question de l’impunité (2015)\r\nDécision du 201e Conseil exécutif de l’UNESCO (201 EX/Décision 5.I.I) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 202e Conseil exécutif de l’UNESCO (202 EX/Décision 5 I.K) sur la sécurité des journalistes et la question de l’impunité (2017)\r\nDécision du 206e Conseil exécutif de l’UNESCO (206 EX/SR.7) sur la sécurité des journalistes et la question de l’impunité (2019)\r\nDécision du 211e Conseil exécutif de l’UNESCO (211 EX/5.I.G) sur la sécurité des journalistes et la question de l’impunité (2021)\r\nDécisions du Conseil intergouvernemental du PIDC\r\n\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2008)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2010)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2012)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2014)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2016)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2018)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2020)\r\nDécision du PIDC sur la sécurité des journalistes et la question de l’impunité (2022)\r\nDéclarations de la Journée mondiale de la liberté de la presse\r\n\r\nDéclaration de Belgrade de l’UNESCO - Soutien aux médias dans les zones de conflit violent et dans les pays en transition (2004)\r\nDéclaration de Medellín de l’UNESCO - Sécurité des journalistes et lutte contre l’impunité (2007)\r\nDéclaration de Carthage de l’UNESCO sur la liberté de la presse et la sécurité des journalistes (2012)\r\nDéclaration de San José de l’UNESCO - Assurer la liberté d’expression dans tous les médias (2013)\r\nDéclaration de Paris de l’UNESCO sur liberté des médias pour un avenir meilleur (2014)\r\nDéclaration de Riga de l’UNESCO sur l’amélioration de l’information, l’égalité des sexes et la sécurité des médias à l’ère du numérique (2015)\r\nDéclaration de la Finlande sur l’accès à l’information et les libertés fondamentales (2016)\r\nDéclaration de Jakarta « Des esprits critiques pour des temps critiques : le rôle des médias dans la promotion de sociétés pacifiques, justes et inclusives » (2017)\r\nDéclaration d’Accra « Médias, justice et état de droit : les contrepoids du pouvoir » (2018)\r\nDéclaration d’Addis-Ababa « Journalisme et élections en temps de désinformation » (2019)\r\nDéclaration de Windhoek+30 (2021)\r\nDéclaration conjointe de l’ONU sur la sécurité des journalistes à l’occasion de la Journée mondiale de la liberté de la presse 2022 (2022)\r\nDéclaration conjointe des Présidents de l’ONU sur la liberté d’expression comme moteur de tous les autres droits de l’homme (2023)\r\nDéclarations conjointes des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression\r\n\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la promotion de liberté d’expression (1999)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la censure par l’assassinat et la diffamation (2000)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes de promotion de la liberté d’expression (2002)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression (2005)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les mécanismes internationaux de promotion de la liberté d’expression (2006)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2010)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les atteintes à la liberté d’expression (2012-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la violence contre les journalistes et les professionnels des médias dans le contexte de manifestations (2013-3)\r\nCommuniqué de presse conjoint des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur une plus grande protection des journalistes couvrant les conflits (2014-2)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les réponses aux situations de conflit (2015)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les défis pour la liberté d’expression lors de la prochaine décennie (2019)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et les élections à l’ère du numérique (2020)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur les politiciens et fonctionnaires et la liberté d’expression (2021)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté d’expression et la justice entre les sexes (2022)\r\nDéclaration conjointe des Rapporteurs spéciaux des Nations Unies sur la liberté d’expression sur la liberté des médias et la démocratie (2023)\r\nProcédure d’Examen périodique universel (incluant la contribution de l’UNESCO)\r\nL’Examen périodique universel (EPU) du Conseil des droits de l’homme est le mécanisme d’établissement de rapports des Nations Unies sur les droits de l’homme dans tous les États membres de l’ONU, auquel l’UNESCO contribue, notamment en ce qui concerne les droits fondamentaux que sont la liberté d’expression, la liberté d’information et la sécurité des journalistes. Il se réunit trois fois par an et donne l’occasion à chaque État membre de déclarer les mesures qu’il a prises pour améliorer les droits de l’homme au sein de ses frontières et remplir ses obligations.\r\n\r\n13e Session (2012) | 14e Session (2012) | 15e Session (2013) | 16e Session (2013) | 17e Session (2013)\r\n\r\n18e Session (2014) | 19e Session (2014) | 20e Session (2014) | 21e Session (2015) | 22e Session (2015)\r\n\r\n23e Session (2015) | 24e Session (2016) | 25e Session (2016) | 26e Session (2016) | 27e Session (2017)\r\n\r\n28e Session (2017) | 29e Session (2018) | 30e Session (2018) | 31e Session (2018) | 32e Session (2019)\r\n\r\n33e Session (2019) | 34e Session (2019) | 35e Session (2020) | 36e Session (2020) | 37e Session (2021)\r\n\r\n38e Session (2021) | 39e Session (2021) | 40e Session (2022) | 41e Session (2022) | 42e Session (2023)\r\n\r\nInstruments régionaux de législation en matière de droits de l’homme\r\nCharte africaine des droits de l’homme et des peuples (1981, en vigueur depuis 1986)\r\nConvention américaine relative aux droits de l’homme (1969, en vigueur depuis 1978)\r\nConvention européenne des droits de l’homme (1950, en vigueur depuis 1953)\r\nCharte arabe des droits de l’homme (2004, en vigueur depuis 2008)\r\nLois et mesures humanitaires\r\nConventions de Genève de 1949 et leurs Protocoles additionnels\r\nRésolution 2 de la 31e Conférence internationale du CICR sur le Plan d’action sur 4 ans (2011)\r\nMesures régionales spécifiques à la sécurité des journalistes\r\nDéclaration finale du Sommet mondial sur la société de l’information (SMSI) +10 (2013), Documents finaux de haut niveau du SMSI+10 (2014) et Résolution de l’Assemblée générale des Nations Unies (A/RES/70/125) sur le document final de la Réunion de haut niveau de l’Assemblée générale sur l’examen d’ensemble de la mise en œuvre des résultats du Sommet mondial sur la société de l’information (2016)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection et la promotion du journalisme d’investigation (2007)\r\nConseil de l’Europe : Déclaration du Comité des ministres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2007)\r\nOrientations de l’UE relatives à la liberté d’expression en ligne et hors ligne (2014)\r\nConseil de l’Europe : Recommandation CM/Rec(2016)4 du Comité des ministres aux États membres sur la protection du journalisme et la sécurité des journalistes et des autres acteurs médiatiques (2016)\r\nDécision MC.DEC.3/18 du Conseil ministériel de l’OSCE sur la sécurité des journalistes (2018)\r\nDéclaration de principes en matière de liberté d’expression et d’accès à l’information en Afrique de la Commission africaine des droits de l’homme et des peuples (2019)\r\nRésolution de la Commission africaine des droits de l’homme et des peuples (ACHPR/Res.468 (LXVII) sur la sécurité des journalistes et les professionnels des médias en Afrique (2020)\r\nRésolution (2317) de l’Assemblée parlementaire du Conseil de l’Europe - Menaces sur la liberté des médias et la sécurité des journalistes en Europe (2020)\r\nConseil de l’Europe : Résolution de la Conférence des ministres responsables de la société des médias et de l’information sur la sécurité des journalistes (2021)\r\nDéclarations intergouvernementales\r\nConférence mondiale sur la liberté des médias : Engagement mondial en faveur de la liberté des médias (2019)\r\nEngagement de La Haye pour accroître la sécurité des journalistes (2020)\r\nDéclaration conjointe des Groupes d’amis sur la sécurité des journalistes sur la liberté de la presse (2021)\r\nDéclaration conjointe du Partenariat mondial d’action contre le harcèlement et les abus sexistes en ligne à l’occasion de la Journée mondiale de la liberté de la presse (2022)\r\nJournée mondiale de la liberté de la presse : Déclaration du Haut représentant au nom de l’Union européenne (2023)\r\nDéclarations des organisations non gouvernementales et de la société civile\r\nDéclaration de Londres des membres de la communauté mondiale des médias sur la sécurité des journalistes et la question de l’impunité (2012)\r\nRecommandations de la Conférence internationale de Varsovie sur la sécurité des journalistes (2013)\r\nPrincipes et pratiques de sécurité globale, un ensemble de normes de sécurité internationales destinées aux reporters indépendants en mission dangereuse, établies par une coalition de grandes sociétés de presse et d’organisations journalistiques (2015)\r\nDéclaration internationale sur la protection des journalistes, par l’Institut international de la presse, l’Institut international pour la sécurité de la presse, African Media Initiative et le Réseau de médias Al Jazeera (2016)\r\nDéclaration commune sur l’indépendance et la diversité des médias à l’ère du numérique (2018)\r\nPartenariat pour l’information et la démocratie, lancé par l’ONG Reporters sans frontières (2019)\r\nCoalition de la Fondation internationale pour les femmes dans les médias contre la violence en ligne (2021)\r\nDéclarations nationales résultant de consultations nationales sur le Plan d’action des Nations Unies\r\nDéclaration d’Islamabad sur la sécurité des journalistes et la question de l’impunité (2012)\r\nPlan d’action philippin sur la sécurité des journalistes (2019)\r\nPlan d’action national du Royaume-Uni de Grande-Bretagne et d’Irlande du Nord pour la sécurité des journalistes (2021)\r\nDécisions clés de la Cour internationale\r\nCarvajal Carvajal c. Columbia (2018). Cour interaméricaine des droits de l’homme\r\nHerzog et al. c. Brésil (2018). Cour interaméricaine des droits de l’homme\r\nJineth Bedoya et al. c. Colombie (2021) Cour interaméricaine des droits de l’homme\r\nShare\r\nCopied to clipboard\r\nThèmes liés\r\nInformation et communication \r\nUNESCO\r\nActualités\r\nCalendar of events\r\nIn brief\r\nNotre impact\r\nNotre Expertise\r\nPortail de données\r\nS'abonner à nos lettres d'information\r\nUNESCO Shop\r\nConditions d'utilisation\r\nUNESCO Logo et Patronage\r\nFAQ\r\nSignaler un cas de fraude, corruption ou autre manquement\r\nMessages Frauduleux\r\nPolitiques\r\nProtection des droits de l’homme (Procédure 104)\r\nPolitique de confidentialité\r\nAccès à l’information\r\nGestion environnementale\r\nFollow us\r\nFacebook\r\nThreads\r\nX\r\nYouTube\r\nInstagram\r\nLinkedIn\r\nNous utilisons des cookies sur ce site pour améliorer votre expérience de navigation. Pour en savoir plus sur notre manière d'utiliser les cookies, lisez notre politique de confidentialité.	2025-02-27 07:19:51	2025-02-27 07:19:51	7
40	Plus gros transferts, belles affaires, clubs et championnats les plus actifs... Le récapitulatif complet du mercato hivernal !	Plan d’action philippin sur la sécurité des journalistes (2019)\r\nA retenir : Plus gros transferts, belles affaires, clubs et championnats les plus actifs... Le récapitulatif complet du mercato hivernal ! OMPSGLyonLilleMonacoChelseaMan UtdArsenalLiverpoolManCity BarcaRealAtleticoMilanJuveInterNaplesBayernDortmund+ de clubs Résultats Classements Calendriers MercatoLigue 1L2/CoupesEtrangerCoupe d'EuropeLes Bleus & InternationalChroniques TV + Résultats Ligue 2 | Résus National | Résus Coupe de France | Résus Coupe de la Ligue | Actu Coupe de France | Actu Coupe de la Ligue | Le PSG met fin au rêve du Stade Briochin - Débrief et NOTES des joueurs (Stade Briochin 0-7 PSG) Par Romain Rigaux - Actu Coupe De France, Mise en ligne: le 26/02/2025 à 23h04 23 Taille du texte: Email Imprimer Tweet Très largement au-dessus, le Paris Saint-Germain a lourdement battu le Stade Briochin (7-0), pensionnaire de National 2, en quart de finale de la Coupe de France. L'épopée s'arrête là pour les Bretons. Joao Neves a lancé le PSG (0-1, 16e). Il n'y a pas eu de miracle pour le Stade Briochin. Pour cela, il aurait fallu que le pensionnaire de National 2 tombe sur un Paris Saint-Germain suffisant. Mais ce n'est plus le genre de la maison chez les Parisiens depuis l'arrivée de Luis Enrique. Les champions de France ont donc respecté leur adversaire et décroché une très large victoire (7-0), ce mercredi au Roazhon Park, pour se qualifier en demi-finale de la Coupe de France. Paris fait le job en première période Très sérieux dès l'entame, les Parisiens ont rapidement concrétisé leur domination dans cette rencontre. Sur une frappe de Doué repoussée par la barre transversale de L'Hostis, Joao Neves enchaînait contrôle poitrine et reprise du gauche dans la surface adverse pour donner l'avantage au Paris SG (0-1, 16e). Six minutes plus tard, Fabian Ruiz est passé tout proche du break sur une frappe qui est venue s'écraser sur la barre transversale. Paris était en maîtrise. Si les Briochins ont réussi à se procurer quelques situations intéressantes sur des contre-attaques, grâce à un Janno remuant mais un peu trop seul devant, l'équipe de Luis Enrique n'a jamais été véritablement mise en danger au cours de la première période. Et Ramos a permis au champion de France de faire le break d'une reprise du pied droit sur un centre de Mayulu vers le second poteau (0-2, 36e). Sans forcer, Paris est rentré aux vestiaires avec un avantage déjà confortable à la pause. Une avalanche de buts après la pause Le PSG a fait le nécessaire pour tuer définitivement le suspense en seconde période. Sur un penalty obtenu par Kvaratskhelia, Ramos a tranquillement donné trois buts d'avance à son équipe (0-3, 49e). Puis le Portugais a bien remisé sur Doué (0-4, 55e), qui a rendu la pareille à son coéquipier en le décalant dans la surface après un joli rush depuis la ligne médiane (0-5, 58e). Derrière, Paris a continué de pousser, et Doué s'est encore montré décisif sur un centre en retrait pour Mayulu (0-6, 66e). Malgré une réaction des Briochins pour tenter d'emballer la fin de match, avec une frappe de Ntumi repoussée par Safonov, Dembélé a creusé un peu plus l'écart sur une contre-attaque (0-7, 85e). La fin du rêve est brutale pour les Bretons. La note du match : 7/10 Il n'y a pas eu match entre les deux équipes. Le Stade Briochin a fait un peu illusion sur quelques contres en début de match, mais le PSG a éteint tout suspense en creusant l'écart au fil des minutes. Il n'y a pas eu de rébellion des pensionnaires de National 2, mais c'est aussi parce que les Parisiens ne leur en n'ont pas laissé l'opportunité. Paris a tout de même fait le spectacle avec sept buts. Les buts : - Servi à l'entrée de la surface, Doué enroule une frappe du pied droit. Le ballon est touché par la tête d'un défenseur et vient taper la barre transversale. Joao Neves contrôle de la poitrine avant de marquer d'une reprise du gauche (0-1, 16e). - Depuis l'entrée de la surface côté gauche, Mayulu envoie un centre vers le second poteau, où Ramos met son pied droit en opposition pour marquer à bout portant (0-2, 36e). - Ramos tire son penalty du pied droit sur la droite de L'Hostis, pris à contre-pied (0-3, 49e). - Sur une remise en retrait de Ramos, Doué contourne la défense adverse sur sa gauche pour marquer d'une frappe du gauche puissante (0-4, 55e). - Doué récupère le ballon à la ligne médiane, puis élimine deux adversaires avant de fixer deux défenseurs dans l'axe de la surface. Il décale sur sa gauche vers Ramos, qui ouvre son pied droit pour marquer (0-5, 58e). - Barcola trouve Doué dans la surface côté gauche. L'ancien Rennais centre en retrait pour Mayulu, qui frappe en force en une touche (0-6, 66e). - Après une récupération au milieu de terrain, Barcola fixe à l'intérieur puis trouve Dembélé dans l'espace. L'attaquant s'excentre un peu dans la surface côté droit avant de marquer d'une frappe puissante du droit entre le gardien et son premier poteau (0-7, 85e). Les NOTES des Parisiens Maxifoot a attribué une note (sur 10) commentée à chaque joueur du PSG. L'homme du match : Désiré Doué (9/10) Le joueur formé au Stade Rennais avait envie de briller sur son ancienne pelouse. Avec sa technique et son culot, le milieu offensif a fait beaucoup de différences au Roazhon Park. Surtout, il est impliqué sur cinq des sept buts parisiens : il a marqué le quatrième, il est double passeur pour Ramos et Mayulu, il est impliqué sur le but de Joao Neves, avec sa frappe sur la barre transversale, puis sa talonnade permet à Kvaratskhelia d'obtenir un penalty. Un super match ! PARIS SG : Matvey Safonov (6) : le gardien russe n'a pas eu grand-chose à faire en première période. Il a été vigilant sur un centre de Gomis, puis a capté une frappe de Yobé. Peu sollicité en seconde période, le portier a bien fermé l'angle sur une occasion de Ntumi. Une soirée sans souci pour la doublure de Donnarumma. Achraf Hakimi (6) : comme à son habitude, le latéral droit a joué très haut sur la pelouse. Le Marocain a participé au jeu en combinant avec ses partenaires, mais on l'a connu plus tranchant dans les derniers mètres. Il n'a pas forcé son talent ce soir. Remplacé à la 62e par Presnel Kimpembe (non noté). Willian Pacho (6) : le défenseur central a fait son match. L'Equatorien a connu quelques difficultés en début de rencontre sur les courses de Janno dans la profondeur, manqué parfois de tranchant dans ses interventions, mais il n'a pas fait d'erreur et a globalement bien défendu sa surface. Lucas Beraldo (6) : titularisé pour faire souffler Marquinhos, le défenseur central a fait un match sérieux face à un adversaire très nettement inférieur. Solide dans le duel et précis dans la relance, le Brésilien a rendu une bonne copie. Lucas Hernandez (6) : titularisé au poste de latéral gauche, le Français a plus souvent joué comme troisième défenseur axial. Dans ce rôle, il n'a pas eu trop d'efforts à faire et il s'est montré juste dans ses transmissions. Un match tranquille pour lui. Remplacé à la 62e par Ousmane Dembélé (non noté), qui s'est offert un nouveau but, son 26e de la saison. Fabian Ruiz (6,5) : un peu timide en début de rencontre, l'Espagnol a haussé le niveau au fil des minutes. Il a alors pris des initiatives avec notamment une frappe repoussée par la barre transversale, alors que le gardien adverse était complètement battu. Avec 111 ballons touchés, 97% de passes réussies et 3 passes clés, l'ancien Napolitain a encore étalé sa justesse au cours de cette rencontre. Senny Mayulu (7) : comme souvent lorsque Luis Enrique lui donne du temps de jeu, le jeune milieu de terrain justifie la confiance de son entraîneur. Encore très disponible, il a constamment offert des solutions à ses coéquipiers pour progresser vers la surface. Il a été décisif avec ce centre vers Ramos pour le but du 2-0, puis en marquant le sixième but parisien. João Neves (7) : le milieu de terrain a encore rendu une bonne copie. Très remuant et à l'aise techniquement, le Portugais s'est baladé dans l'entrejeu. Il s'est montré à l'aise dans la surface adverse aussi, avec cet enchaînement contrôle poitrine et reprise du gauche pour donner l'avantage à son équipe. Remplacé à la 66e par Warren Zaïre-Emery (non noté), qui a rejoué après près d'un mois d'absence. Désiré Doué (9) : lire le commentaire ci-dessus. Gonçalo Ramos (9) : titularisé à la pointe de l'attaque parisienne, le Portugais a fait le job. L'avant-centre parisien a permis au PSG de faire le break en reprenant un centre de Mayulu au second poteau. Puis il n'a pas tremblé pour marquer un penalty. Il s'est ensuite mué en passeur pour Doué, avant de s'offrir un triplé sur une offrande de ce même Doué. Remplacé à la 77e par Ibrahim Mbaye (non noté). Khvicha Kvaratskhelia (6) : le Géorgien a livré une première période moyenne. S'il a été disponible pour ses partenaires, l'ancien Napolitain a eu du mal à faire des différences sur son côté gauche, et on l'a senti agacé par ce manque de réussite. Il est mieux revenu après la pause. C'est lui qui a obtenu le penalty du 2-0 sur une combinaison avec Doué. Remplacé à la 62e par Bradley Barcola (non noté), impliqué sur les deux derniers buts parisiens. + Retrouvez les résultats de Coupe de France sur Maxifoot Et pour vous, quels ont été les meilleurs et les moins bons joueurs du match ? Réagissez dans la zone de "commentaires" ci-dessous ! STADE BRIOCHIN 0-7 PARIS SG (mi-tps: 0-2) - FRANCE - Coupe de France / 1/4 Stade : - Arbitre : Leonard, Thomas, France Buts : - João Neves (16e) Gonçalo Ramos (36e) Gonçalo Ramos (48e, pen.) D. Doué (55e) Gonçalo Ramos (58e) S. Mayulu (66e) O. Dembélé (85e) pour PARIS SG Avertissements : STADE BRIOCHIN : F. L'Hostis - B. Angoua, C. Kerbrat, H. Boudin - J. Le Marer, M. Diakite (B. Diakhaby, 64e) - L. Yobé, G. Beghin (C. Konan, 64e), A. Zakharyan (L. Rouillé, 77e) - A. Gomis-Maillard (M. Ntumi, 71e), Stan Janno (J. Benhaim, 64e) PARIS SG : M. Safonov - Beraldo, W. Pacho - A. Hakimi (O. Dembélé, 62e), L. Hernández (P. Kimpembe, 62e) - João Neves (W. Zaïre-Emery, 66e), Fabián Ruiz, S. Mayulu - D. Doué, Gonçalo Ramos (I. Mbaye, 77e), K. Kvaratskhelia (B. Barcola, 62e) Ramos a inscrit un triplé Doué était intenable ! Encore une prestation convaincante pour le jeune Mayulu La Coupe de France s'arrête en quarts pour les valeureux Briochins Partager sur FacebookPartager sur Twitter Un problème avec cet article ? Prévenez-nous en cliquant sur ce lien Contenus Sponsorisés Recommandé pour vous Le Canada est ouvert aux Malagaches PR Canadiense Lissez votre double menton en utilisant ceci 5 minutes par jour Revue Beauté Les retraités ne paient rien grâce à cette mutuelle Mutuelle Santé Sénior En savoir plus par Taboola REAGISSEZ : Communauté   FACEBOOK Communauté   DISQUS Pour signaler un abus, contactez moderation-abus@maxifoot.fr Pour afficher les commentaires Facebook, vous devez être connecté à Facebook Contenus Sélectionnés À Découvrir Aussi Les retraités ne paient rien grâce cette mutuelle Mutuelle Santé Sénior Real : Modric, 39 ans, vraiment ? L'esthéticienne de célébrités révèle un truc pour une peau plus jeune Revue Beauté REAGISSEZ : Communauté   FACEBOOK Communauté   DISQUS chargement des commentaires disqUS ...     Liens FRANCE - Ligue 2 / CdF / CdL Résultats & Classement L2 Classement des buteurs de L2 Calendrier L2 complet Actualité de la Coupe de France Calendrier & résultats Coupe de France Palmarès de la Coupe de France Actualité de la Coupe de la Ligue Calendrier & résultats Coupe de la Ligue Palmarès de la Coupe de la Ligue Sondage Maxifoot Le PSG (0 défaite en 23 journées) va-t-il finir la saison invaincu en Ligue 1 ? OUI NON Voter Voir les resultats - Voir les sondages précédents Actu et transferts 24h/24 23h57OM : Longoria, la commission se justifie 23h46OM : le club réagit à la suspension de Longoria 23h41PSG : une soirée parfaite pour Luis Enrique 23h33Saint-Brieuc : Allanou chambre Brest ! 23h29Esp. (Cpe) : une option pour le Real 23h20PSG : le triplé ? Ramos en veut d'autres 23h18OM : 3 matchs de suspension pour Ravanelli 23h13Ang. : Liverpool se rapproche du titre 23h12Saint-Brieuc : Kerbrat admiratif du PSG 23h07Ita. (Cpe) : la Juve éliminée aux tirs au but ! 22h59CdF : Stade Briochin 0-7 PSG (fini) 22h52Brest : E. Roy - "une grande désillusion" 22h40All. (Cpe) : Leipzig rejoint les demi-finales 22h30Ang. : MU s'impose à 10 contre 11 22h29Ang. : Man City se relance à Tottenham 22h26Ang. : Arsenal encore ralenti à Nottingham 22h25OM : Longoria suspendu 15 matchs ! 22h13Blackburn : Ismaël a signé (officiel) 21h39VIDEOS : boulette, rouge, Dorgu plombe MU ! 21h22OM : Longoria, Pignard a été choqué 21h17Brest : l'immense déception de Chardonnet 21h10Dunkerque : Sangante sur un nuage 20h55CdF : Dunkerque élimine Brest ! 20h34Stuttgart : Rieder devrait retourner à Rennes Voir les brèves précédentes Les + populaires du moment 25/02OM : Di Meco ne veut pas de la vie de Longoria 25/02OM : Dugarry dézingue Longoria ! 26/02Al Nassr : match retardé, Ronaldo s'excuse 26/02OM : Stinat sort du silence 25/02OM-Nantes : Frappart, le message du SAFE 25/02OM : le patron des arbitres prêt à discuter ? 25/02OM : Longoria a parlé à la ministre des Sports 26/02PSG : l'Arabie Saoudite offre 200 M€ à Campos ! Les VIDEOS populaires du moment Voir toutes les vidéos emplacement publicitaire  A SUIVRE TOP 15 PEPITES jeunes de Ligue 1 Le meilleur effectif LIGUE 1 mi-saison 2024-25 FLOP transferts en Ligue1 mi-saison 2024-25 Classements des BUTEURS en EUROPE Indice MF : l'état de FORME des clubs en europe Les FRANCAIS à l'ETRANGER Qui joue ? Qui marque ? S T A D E B R I O C H I N P A R I S S G - L'Hostis - Angoua - Kerbrat - Boudin - Le Marer - Diakite - Yobé - Beghin - Zakharyan - Gomis-Maillard - 776621--> - Safonov - Beraldo - Pacho - Hakimi - Hernández - Neves - Ruiz - Mayulu - Doué 3 - Ramos - Kvaratskhelia MASQUER LA PUB Maxifoot (100% Football) : l'actualité du foot, des transferts et du mercato 24h/24   Contacts La rédaction Publicité Recrutement Infos légales Liens football Services Maxifoot Appli Maxifoot Android Appli Maxifoot iPhone Site web Mobile Choix de consentement Flux RSS info foot Liens privilégiés Liens football Maxifoot-Live (livescore) Cinema et DVD Non au racisme © copyright Advimedia - Maxifoot 2000-2024 Ajouter Maxifoot à vos favoris - Source: Maxifoot, https://www.maxifoot.fr/football/article-60519.htm#footref	2025-02-27 07:20:34	2025-02-27 07:20:34	7
41	Fabian Ruiz est passé tout proche du break	Plus gros transferts, belles affaires, clubs et championnats les plus actifs... Le récapitulatif complet du mercato hivernal ! sérieux dès l'entame, les Parisiens ont rapidement concrétisé leur domination dans cette rencontre. Sur une frappe de Doué repoussée par la barre transversale de L'Hostis, Joao Neves enchaînait contrôle poitrine et reprise du gauche dans la surface adverse pour donner l'avantage au Paris SG (0-1, 16e). Six minutes plus tard, Fabian Ruiz est passé tout proche du break sur une frappe qui est venue s'écraser sur la barre transversale. Paris était en maîtrise. Si les Briochins ont réussi à se procurer quelques situations intéressantes sur des contre-attaques, grâce à un Janno remuant mais un peu trop seul devant, l'équipe de Luis Enrique n'a jamais été véritablement mise en danger au cours de la première période. Et Ramos a permis au champion de France de faire le break d'une reprise du pied droit sur un centre de Mayulu vers le second poteau (0-2, 36e). Sans forcer, Paris est rentré aux vestiaires avec un avantage déjà confortable à la pause. Une avalanche de buts après la pause Le PSG a fait le nécessaire pour tuer définitivement le suspense en seconde période. Sur un penalty obtenu par Kvaratskhelia, Ramos a tranquillement donné trois buts d'avance à son équipe (0-3, 49e). Puis le Portugais a bien remisé sur Doué (0-4, 55e), qui a rendu la pareille à son coéquipier en le décalant dans la surface après un joli rush depuis la ligne médiane (0-5, 58e). Derrière, Paris a continué de pousser, et Doué s'est encore montré décisif sur un centre en retrait pour Mayulu (0-6, 66e). Malgré une réaction des Briochins pour tenter d'emballer la fin de match, avec une frappe de Ntumi repoussée par Safonov, Dembélé a creusé un peu plus l'écart sur une contre-attaque (0-7, 85e). La fin du rêve est brutale pour les Bretons. La note du match : 7/10 Il n'y a pas eu match entre les deux équipes. Le Stade Briochin a fait un peu illusion sur quelques contres en début de match, mais le PSG a éteint tout suspense en creusant l'écart au fil des minutes. Il n'y a pas eu de rébellion des pensionnaires de National 2, mais c'est aussi parce que les Parisiens ne leur en n'ont pas laissé l'opportunité. Paris a tout de même fait le spectacle avec sept buts. Les buts : - Servi à l'entrée de la surface, Doué enroule une frappe du pied droit. Le ballon est touché par la tête d'un défenseur et vient taper la barre transversale. Joao Neves contrôle de la poitrine avant de marquer d'une reprise du gauche (0-1, 16e). - Depuis l'entrée de la surface côté gauche, Mayulu envoie un centre vers le second poteau, où Ramos met son pied droit en opposition pour marquer à bout portant (0-2, 36e). - Ramos tire son penalty du pied droit sur la droite de L'Hostis, pris à contre-pied (0-3, 49e). - Sur une remise en retrait de Ramos, Doué contourne la défense adverse sur sa gauche pour marquer d'une frappe du gauche puissante (0-4, 55e). - Doué récupère le ballon à la ligne médiane, puis élimine deux adversaires avant de fixer deux défenseurs dans l'axe de la surface. Il décale sur sa gauche vers Ramos, qui ouvre son pied droit pour marquer (0-5, 58e). - Barcola trouve Doué dans la surface côté - Source: Maxifoot, https://www.maxifoot.fr/football/article-60519.htm#footref	2025-02-27 07:21:31	2025-02-27 07:21:31	8
42	Plus gros transferts, belles affaires	Plus gros transferts, belles affaires, clubs et championnats les plus actifs... Le récapitulatif complet du mercato hivernal ! sérieux dès l'entame, les Parisiens ont rapidement concrétisé leur domination dans cette rencontre. Sur une frappe de Doué repoussée par la barre transversale de L'Hostis, Joao Neves enchaînait contrôle poitrine et reprise du gauche dans la surface adverse pour donner l'avantage au Paris SG (0-1, 16e). Six minutes plus tard, Fabian Ruiz est passé tout proche du break sur une frappe qui est venue s'écraser sur la barre transversale. Paris était en maîtrise. Si les Briochins ont réussi à se procurer quelques situations intéressantes sur des contre-attaques, grâce à un Janno remuant mais un peu trop seul devant, l'équipe de Luis Enrique n'a jamais été véritablement mise en danger au cours de la première période. Et Ramos a permis au champion de France de faire le break d'une reprise du pied droit sur un centre de Mayulu vers le second poteau (0-2, 36e). Sans forcer, Paris est rentré aux vestiaires avec un avantage déjà confortable à la pause. Une avalanche de buts après la pause Le PSG a fait le nécessaire pour tuer définitivement le suspense en seconde période. Sur un penalty obtenu par Kvaratskhelia, Ramos a tranquillement donné trois buts d'avance à son équipe (0-3, 49e). Puis le Portugais a bien remisé sur Doué (0-4, 55e), qui a rendu la pareille à son coéquipier en le décalant dans la surface après un joli rush depuis la ligne médiane (0-5, 58e). Derrière, Paris a continué de pousser, et Doué s'est encore montré décisif sur un centre en retrait pour Mayulu (0-6, 66e). Malgré une réaction des Briochins pour tenter d'emballer la fin de match, avec une frappe de Ntumi repoussée par Safonov, Dembélé a creusé un peu plus l'écart sur une contre-attaque (0-7, 85e). La fin du rêve est brutale pour les Bretons. La note du match : 7/10 Il n'y a pas eu match entre les deux équipes. Le Stade Briochin a fait un peu illusion sur quelques contres en début de match, mais le PSG a éteint tout suspense en creusant l'écart au fil des minutes. Il n'y a pas eu de rébellion des pensionnaires de National 2, mais c'est aussi parce que les Parisiens ne leur en n'ont pas laissé l'opportunité. Paris a tout de même fait le spectacle avec sept buts. Les buts : - Servi à l'entrée de la surface, Doué enroule une frappe du pied droit. Le ballon est touché par la tête d'un défenseur et vient taper la barre transversale. Joao Neves contrôle de la poitrine avant de marquer d'une reprise du gauche (0-1, 16e). - Depuis l'entrée de la surface côté gauche, Mayulu envoie un centre vers le second poteau, où Ramos met son pied droit en opposition pour marquer à bout portant (0-2, 36e). - Ramos tire son penalty du pied droit sur la droite de L'Hostis, pris à contre-pied (0-3, 49e). - Sur une remise en retrait de Ramos, Doué contourne la défense adverse sur sa gauche pour marquer d'une frappe du gauche puissante (0-4, 55e). - Doué récupère le ballon à la ligne médiane, puis élimine deux adversaires avant de fixer deux défenseurs dans l'axe de la surface. Il décale sur sa gauche vers Ramos, qui ouvre son pied droit pour marquer (0-5, 58e). - Barcola trouve Doué dans la surface côté - Source: Maxifoot, https://www.maxifoot.fr/football/article-60519.htm#footref	2025-02-27 07:21:56	2025-02-27 07:21:56	7
44	Servi à l'entrée de la surfacesérieux dès l'entame	Servi à l'entrée de la surfacesérieux dès l'entame, les Parisiens ont rapidement concrétisé leur domination dans cette rencontre. Sur une frappe de Doué repoussée par la barre transversale de L'Hostis, Joao Neves enchaînait contrôle poitrine et reprise du gauche dans la surface adverse pour donner l'avantage au Paris SG (0-1, 16e). Six minutes plus tard, Fabian Ruiz est passé tout proche du break sur une frappe qui est venue s'écraser sur la barre transversale. Paris était en maîtrise. Si les Briochins ont réussi à se procurer quelques situations intéressantes sur des contre-attaques, grâce à un Janno remuant mais un peu trop seul devant, l'équipe de Luis Enrique n'a jamais été véritablement mise en danger au cours de la première période. Et Ramos a permis au champion de France de faire le break d'une reprise du pied droit sur un centre de Mayulu vers le second poteau (0-2, 36e). Sans forcer, Paris est rentré aux vestiaires avec un avantage déjà confortable à la pause. Une avalanche de buts après la pause Le PSG a fait le nécessaire pour tuer définitivement le suspense en seconde période. Sur un penalty obtenu par Kvaratskhelia, Ramos a tranquillement donné trois buts d'avance à son équipe (0-3, 49e). Puis le Portugais a bien remisé sur Doué (0-4, 55e), qui a rendu la pareille à son coéquipier en le décalant dans la surface après un joli rush depuis la ligne médiane (0-5, 58e). Derrière, Paris a continué de pousser, et Doué s'est encore montré décisif sur un centre en retrait pour Mayulu (0-6, 66e). Malgré une réaction des Briochins pour tenter d'emballer la fin de match, avec une frappe de Ntumi repoussée par Safonov, Dembélé a creusé un peu plus l'écart sur une contre-attaque (0-7, 85e). La fin du rêve est brutale pour les Bretons. La note du match : 7/10 Il n'y a pas eu match entre les deux équipes. Le Stade Briochin a fait un peu illusion sur quelques contres en début de match, mais le PSG a éteint tout suspense en creusant l'écart au fil des minutes. Il n'y a pas eu de rébellion des pensionnaires de National 2, mais c'est aussi parce que les Parisiens ne leur en n'ont pas laissé l'opportunité. Paris a tout de même fait le spectacle avec sept buts. Les buts : - Servi à l'entrée de la surface, Doué enroule une frappe du pied droit. Le ballon est touché par la tête d'un défenseur et vient taper la barre transversale. Joao Neves contrôle de la poitrine avant de marquer d'une reprise du gauche (0-1, 16e). - Depuis l'entrée de la surface côté gauche, Mayulu envoie un centre vers le second poteau, où Ramos met son pied droit en opposition pour marquer à bout portant (0-2, 36e). - Ramos tire son penalty du pied droit sur la droite de L'Hostis, pris à contre-pied (0-3, 49e). - Sur une remise en retrait de Ramos, Doué contourne la défense adverse sur sa gauche pour marquer d'une frappe du gauche puissante (0-4, 55e). - Doué récupère le ballon à la ligne médiane, puis élimine deux adversaires avant de fixer deux défenseurs dans l'axe de la surface. Il décale sur sa gauche vers Ramos, qui ouvre son pied droit pour marquer (0-5, 58e). - Barcola trouve Doué dans la surface côté - Source: Maxifoot, https://www.maxifoot.fr/football/article-60519.htm#footref	2025-02-27 07:23:28	2025-02-27 07:23:28	7
43	Le récapitulatif complet du mercato hivernal !	Plus gros transferts, belles affaires, clubs et championnats les plus actifs... Le récapitulatif complet du mercato hivernal ! sérieux dès l'entame, les Parisiens ont rapidement concrétisé leur domination dans cette rencontre. Sur une frappe de Doué repoussée par la barre transversale de L'Hostis, Joao Neves enchaînait contrôle poitrine et reprise du gauche dans la surface adverse pour donner l'avantage au Paris SG (0-1, 16e). Six minutes plus tard, Fabian Ruiz est passé tout proche du break sur une frappe qui est venue s'écraser sur la barre transversale. Paris était en maîtrise. Si les Briochins ont réussi à se procurer quelques situations intéressantes sur des contre-attaques, grâce à un Janno remuant mais un peu trop seul devant, l'équipe de Luis Enrique n'a jamais été véritablement mise en danger au cours de la première période. Et Ramos a permis au champion de France de faire le break d'une reprise du pied droit sur un centre de Mayulu vers le second poteau (0-2, 36e). Sans forcer, Paris est rentré aux vestiaires avec un avantage déjà confortable à la pause. Une avalanche de buts après la pause Le PSG a fait le nécessaire pour tuer définitivement le suspense en seconde période. Sur un penalty obtenu par Kvaratskhelia, Ramos a tranquillement donné trois buts d'avance à son équipe (0-3, 49e). Puis le Portugais a bien remisé sur Doué (0-4, 55e), qui a rendu la pareille à son coéquipier en le décalant dans la surface après un joli rush depuis la ligne médiane (0-5, 58e). Derrière, Paris a continué de pousser, et Doué s'est encore montré décisif sur un centre en retrait pour Mayulu (0-6, 66e). Malgré une réaction des Briochins pour tenter d'emballer la fin de match, avec une frappe de Ntumi repoussée par Safonov, Dembélé a creusé un peu plus l'écart sur une contre-attaque (0-7, 85e). La fin du rêve est brutale pour les Bretons. La note du match : 7/10 Il n'y a pas eu match entre les deux équipes. Le Stade Briochin a fait un peu illusion sur quelques contres en début de match, mais le PSG a éteint tout suspense en creusant l'écart au fil des minutes. Il n'y a pas eu de rébellion des pensionnaires de National 2, mais c'est aussi parce que les Parisiens ne leur en n'ont pas laissé l'opportunité. Paris a tout de même fait le spectacle avec sept buts. Les buts : - Servi à l'entrée de la surface, Doué enroule une frappe du pied droit. Le ballon est touché par la tête d'un défenseur et vient taper la barre transversale. Joao Neves contrôle de la poitrine avant de marquer d'une reprise du gauche (0-1, 16e). - Depuis l'entrée de la surface côté gauche, Mayulu envoie un centre vers le second poteau, où Ramos met son pied droit en opposition pour marquer à bout portant (0-2, 36e). - Ramos tire son penalty du pied droit sur la droite de L'Hostis, pris à contre-pied (0-3, 49e). - Sur une remise en retrait de Ramos, Doué contourne la défense adverse sur sa gauche pour marquer d'une frappe du gauche puissante (0-4, 55e). - Doué récupère le ballon à la ligne médiane, puis élimine deux adversaires avant de fixer deux défenseurs dans l'axe de la surface. Il décale sur sa gauche vers Ramos, qui ouvre son pied droit pour marquer (0-5, 58e). - Barcola trouve Doué dans la surface côté - Source: Maxifoot, https://www.maxifoot.fr/football/article-60519.htm#footref	2025-02-27 07:22:14	2025-02-27 07:52:00	7
45	OM : Longoria prend 15 matchs de suspension ! - Source	ugé ce mercredi soir devant la commission de la discipline de la Ligue de football professionnel, pour avoir remis en cause l'intégrité de l'arbitre Jérémy Stinat lors de la défaite à Auxerre (0-3) samedi en Ligue 1, le président de l'Olympique de Marseille Pablo Longoria a écopé de 15 matchs de suspension. Pablo Longoria suspendu jusqu'au début de la saison prochaine ! Le président de l'Olympique de Marseille Pablo Longoria savait qu'il n'allait pas pouvoir échapper à une lourde sanction, après avoir utilisé le terme «corruption» pour qualifier l'arbitrage de Jérémy Stinat, samedi, en marge du match entre Auxerre et l'OM (3-0) en Ligue 1. La commission de discipline de la Ligue de football professionnel (LFP), qui s'est emparée du cas du dirigeant phocéen dès ce mercredi compte tenu de la gravité de ses propos, a entendu l'Espagnol dans la soirée puis a tranché, en lui infligeant une suspension de 15 matchs ! De cette manière, Longoria sera privé de ses fonctions officielles pour la fin de la saison en cours, puis le début de la suivante. Longoria avait fait son mea culpa Le président de l'OM avait dégoupillé, à la suite d'une éventuelle faute sur Quentin Merlin dans la surface auxerroise, non signalée par l'arbitre, et d'un deuxième carton jaune adressé à Derek Cornelius, qu'il a jugé abusif. Deux choix de M. Stinat soutenus par la Direction technique de l'arbitrage mardi soir (voir article ici). Après avoir crié haut et fort à la corruption dans les couloirs de l'Abbé-Deschamps, Longoria a été victime d'une plainte de tous les arbitres de Ligue 1 et Ligue 2 à son encontre. Lundi, le président marseillais avait cependant réalisé son mea culpa : «Il n'y a pas de corruption dans le foot français. La forme n'était pas appropriée et ce mot, je le regrette», avait-il tempéré auprès de l'AFP. Insuffisant pour lui épargner une longue suspension. Cette sanction contre Pablo Longoria vous semble-t-elle appropriée ? N'hésitez pas - Source: Maxifoot, https://www.maxifoot.fr/football/article-60518.htm#footref	2025-02-27 07:52:59	2025-02-28 08:54:08	7
46	Sécurité des journalistes	Le journalisme, une profession essentielle mais dangereuse\r\nLe journalisme est essentiel au développement durable, à la protection des droits de l'homme et à la consolidation de la démocratie, mais reste une profession dangereuse et trop souvent mortelle - et neuf fois sur dix, l'assassinat d'un journaliste n'est pas élucidé.\r\n\r\nSelon l'Observatoire des journalistes assassinés de l'Organisation des Nations Unies pour l'éducation, la science et la culture (UNESCO), plus de 1600 journalistes ont été tués depuis 1993.\r\n\r\nD'autres menaces contre les journalistes se multiplient, en ligne et hors ligne, en particulier dans les zones sans conflit. L'emprisonnement des journalistes atteint un niveau record, tandis que la violence en ligne - en particulier à l'encontre des femmes journalistes - et le harcèlement incitent à l'autocensure et, dans certains cas, à l'agression physique.\r\n\r\nLes journalistes sont également de plus en plus souvent attaqués lorsqu'ils couvrent des manifestations, tant par les forces de sécurité que par des participants aux manifestations.\r\n\r\nDe nombreux rapports et études confirment que les menaces touchent plus particulièrement les femmes journalistes et ceux qui représentent des groupes minoritaires.\r\n\r\nCessez de vous en prendre à la vérité et à celles et ceux qui la font jaillir.\r\nLe monde se tient aux côtés de	2025-03-03 09:02:01	2025-03-03 09:02:01	\N
\.


--
-- Data for Name: authors; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.authors (id, name, bio, age, email, phone, photo, created_at, updated_at) FROM stdin;
2	Bert Wyman	Qui cum quia vel ipsam repellendus. Dolorem et et non ut doloremque.	80	whitney43@example.com	+1.405.336.1271	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
3	Issac Hudson	Perferendis voluptates in voluptas vero deleniti accusamus. Numquam corporis sint id facilis quasi repellat. Eos consequatur velit sunt magni. Quia molestiae et non maxime aut et.	28	qwaelchi@example.org	(903) 393-5448	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
4	Emmy Yundt	Expedita ex non id voluptas minus occaecati. Temporibus quo ut id architecto. Consequuntur nulla maxime laudantium fugit. Sunt nulla sit consequuntur reprehenderit incidunt eos et.	22	wprosacco@example.org	1-612-342-1158	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
5	Elisabeth Mosciski II	Qui repudiandae fuga debitis eum est et et. Dicta natus inventore est vel dolores autem eaque non. Deleniti quas culpa optio dolor earum voluptates. Aut inventore debitis eaque.	19	era.crist@example.org	+1-361-766-0518	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
9	Leif Goldner	In deleniti deleniti tenetur optio ad fugiat. Sit blanditiis natus sit et. Laboriosam deleniti harum sed quod maxime. Nobis tenetur delectus nihil ut.	66	nia86@example.org	(678) 631-6661	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
10	Zoey Heathcote	Fugit ipsa et consequatur nesciunt debitis dolorum nemo. Modi ab nisi qui eum ut earum. In delectus qui porro id. In placeat ab molestiae ut.	51	estrosin@example.net	+1.580.955.3939	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
11	Dr. Lane Hane	Placeat amet velit et assumenda aliquid. Suscipit quis fuga est dolor aut voluptatem. Sit a consequatur et itaque maiores. Pariatur et provident est.	38	alene.hudson@example.net	1-352-623-0077	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
12	Johnson Hoeger	Et non cumque doloremque dicta. Magnam consequatur pariatur tempore ipsum voluptates. Dignissimos tempore dolores quia voluptatibus omnis. Ut neque blanditiis consequatur esse sed consectetur ut.	57	estella90@example.com	720-365-5891	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
13	Flavie Hand Sr.	Aut necessitatibus quae eaque. Optio illo perspiciatis et vel aut. Sapiente blanditiis sunt qui quibusdam. Dolorem aperiam distinctio accusamus vel sed dolore odio.	28	herman.ebony@example.org	857.618.9770	\N	2025-02-26 16:57:04	2025-02-26 16:57:04
14	Forrest McGlynn	Pariatur est libero tempore alias magni non. Voluptate earum repudiandae quae nisi aut. Voluptatem sunt aperiam sint vel omnis corrupti.	49	cesar.lockman@example.com	+1 (276) 422-6141	\N	2025-02-26 16:57:05	2025-02-26 16:57:05
15	Dr. Tia Huels II	At sint aut minima ut. Voluptatum sunt dolorem nemo ut. Delectus fugiat quae et ut minus omnis ab. Recusandae repellat qui nulla est eos.	72	nolan.domingo@example.com	(301) 838-4415	\N	2025-02-26 16:57:05	2025-02-26 16:57:05
8	Leonie Keeling DDS	Est architecto ut rerum et quidem sint. Corporis ut nemo laudantium ipsa vero saepe tempore. Nisi labore et soluta est non a adipisci.	35	sheila76@example.org	+1-785-243-8772	authors/15VoF6FoPqiWPiOXHAlczHQcPflKLs3e85FsZHDV.png	2025-02-26 16:57:04	2025-02-26 20:01:05
1	Gabriel Andriamahafaly	Accusamus minima voluptatem nisi quo eum ea sit. Ullam saepe sunt voluptatem nisi doloribus. Optio voluptatem incidunt totam quae illo. Placeat et quos voluptas veritatis recusandae iusto.	28	gestalkana@gmail.com	1-251-218-9830	authors/RAIxNRwOvlpnEANj1gNSK3aUjDpT0N57t7BwpmoA.jpg	2025-02-26 16:57:04	2025-02-26 17:27:12
6	Dr. Jonathan Kihn I	Voluptatem aut atque sed rerum qui. Eius dolores repudiandae magni qui impedit. Sapiente nemo fugit quis alias similique. Dolor dolore est id consequuntur et aut maiores.	40	lblick@example.com	+19494268097	authors/T6IounxuHtuhyxjRBEBTApNDiijwAYJMUKVODZgH.png	2025-02-26 16:57:04	2025-02-26 19:51:37
7	Prof. Madie Douglas MD	Provident explicabo ab harum aut necessitatibus. Ex fuga dignissimos fugiat tempora et quas a non. Maxime accusantium quisquam dolor sit. Veritatis commodi delectus quibusdam neque voluptas error.	42	tgerhold@example.net	641.880.7948	authors/qO6Y1Eas3aqOYEqcNWTtdivsdiinzk7aylzvFS9T.png	2025-02-26 16:57:04	2025-02-26 19:52:25
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	2014_10_12_000000_create_users_table	1
2	2014_10_12_100000_create_password_reset_tokens_table	1
3	2019_08_19_000000_create_failed_jobs_table	1
4	2019_12_14_000001_create_personal_access_tokens_table	1
5	2024_07_19_154614_create_articles_table	1
6	2024_07_23_180324_create_authors_table	1
7	2024_07_29_165439_add_author_id_to_articles_table	1
\.


--
-- Data for Name: password_reset_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_reset_tokens (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, expires_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Name: articles_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.articles_id_seq', 46, true);


--
-- Name: authors_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.authors_id_seq', 15, true);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 7, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: articles articles_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.articles
    ADD CONSTRAINT articles_pkey PRIMARY KEY (id);


--
-- Name: authors authors_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.authors
    ADD CONSTRAINT authors_email_unique UNIQUE (email);


--
-- Name: authors authors_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.authors
    ADD CONSTRAINT authors_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: password_reset_tokens password_reset_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.password_reset_tokens
    ADD CONSTRAINT password_reset_tokens_pkey PRIMARY KEY (email);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- Name: articles articles_author_id_foreign; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.articles
    ADD CONSTRAINT articles_author_id_foreign FOREIGN KEY (author_id) REFERENCES public.authors(id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

--
-- Database "postgres" dump
--

\connect postgres

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "sayna" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: sayna; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE sayna WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE sayna OWNER TO postgres;

\connect sayna

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: articles; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.articles (
    id bigint NOT NULL,
    titre character varying(255) NOT NULL,
    contenu text NOT NULL,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.articles OWNER TO postgres;

--
-- Name: articles_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.articles_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.articles_id_seq OWNER TO postgres;

--
-- Name: articles_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.articles_id_seq OWNED BY public.articles.id;


--
-- Name: failed_jobs; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.failed_jobs (
    id bigint NOT NULL,
    uuid character varying(255) NOT NULL,
    connection text NOT NULL,
    queue text NOT NULL,
    payload text NOT NULL,
    exception text NOT NULL,
    failed_at timestamp(0) without time zone DEFAULT CURRENT_TIMESTAMP NOT NULL
);


ALTER TABLE public.failed_jobs OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.failed_jobs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.failed_jobs_id_seq OWNER TO postgres;

--
-- Name: failed_jobs_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.failed_jobs_id_seq OWNED BY public.failed_jobs.id;


--
-- Name: migrations; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.migrations (
    id integer NOT NULL,
    migration character varying(255) NOT NULL,
    batch integer NOT NULL
);


ALTER TABLE public.migrations OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.migrations_id_seq OWNER TO postgres;

--
-- Name: migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.migrations_id_seq OWNED BY public.migrations.id;


--
-- Name: password_resets; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.password_resets (
    email character varying(255) NOT NULL,
    token character varying(255) NOT NULL,
    created_at timestamp(0) without time zone
);


ALTER TABLE public.password_resets OWNER TO postgres;

--
-- Name: personal_access_tokens; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.personal_access_tokens (
    id bigint NOT NULL,
    tokenable_type character varying(255) NOT NULL,
    tokenable_id bigint NOT NULL,
    name character varying(255) NOT NULL,
    token character varying(64) NOT NULL,
    abilities text,
    last_used_at timestamp(0) without time zone,
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.personal_access_tokens OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.personal_access_tokens_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.personal_access_tokens_id_seq OWNER TO postgres;

--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.personal_access_tokens_id_seq OWNED BY public.personal_access_tokens.id;


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint NOT NULL,
    name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    email_verified_at timestamp(0) without time zone,
    password character varying(255) NOT NULL,
    remember_token character varying(100),
    created_at timestamp(0) without time zone,
    updated_at timestamp(0) without time zone
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- Name: articles id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.articles ALTER COLUMN id SET DEFAULT nextval('public.articles_id_seq'::regclass);


--
-- Name: failed_jobs id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs ALTER COLUMN id SET DEFAULT nextval('public.failed_jobs_id_seq'::regclass);


--
-- Name: migrations id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations ALTER COLUMN id SET DEFAULT nextval('public.migrations_id_seq'::regclass);


--
-- Name: personal_access_tokens id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens ALTER COLUMN id SET DEFAULT nextval('public.personal_access_tokens_id_seq'::regclass);


--
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- Data for Name: articles; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.articles (id, titre, contenu, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: failed_jobs; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.failed_jobs (id, uuid, connection, queue, payload, exception, failed_at) FROM stdin;
\.


--
-- Data for Name: migrations; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.migrations (id, migration, batch) FROM stdin;
1	2014_10_12_000000_create_users_table	1
2	2014_10_12_100000_create_password_resets_table	1
3	2019_08_19_000000_create_failed_jobs_table	1
4	2019_12_14_000001_create_personal_access_tokens_table	1
5	2024_11_25_142646_create_articles_table	1
\.


--
-- Data for Name: password_resets; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.password_resets (email, token, created_at) FROM stdin;
\.


--
-- Data for Name: personal_access_tokens; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.personal_access_tokens (id, tokenable_type, tokenable_id, name, token, abilities, last_used_at, created_at, updated_at) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, name, email, email_verified_at, password, remember_token, created_at, updated_at) FROM stdin;
\.


--
-- Name: articles_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.articles_id_seq', 1, false);


--
-- Name: failed_jobs_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.failed_jobs_id_seq', 1, false);


--
-- Name: migrations_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.migrations_id_seq', 5, true);


--
-- Name: personal_access_tokens_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.personal_access_tokens_id_seq', 1, false);


--
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, false);


--
-- Name: articles articles_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.articles
    ADD CONSTRAINT articles_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_pkey PRIMARY KEY (id);


--
-- Name: failed_jobs failed_jobs_uuid_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.failed_jobs
    ADD CONSTRAINT failed_jobs_uuid_unique UNIQUE (uuid);


--
-- Name: migrations migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.migrations
    ADD CONSTRAINT migrations_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_pkey PRIMARY KEY (id);


--
-- Name: personal_access_tokens personal_access_tokens_token_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.personal_access_tokens
    ADD CONSTRAINT personal_access_tokens_token_unique UNIQUE (token);


--
-- Name: users users_email_unique; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_email_unique UNIQUE (email);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: password_resets_email_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX password_resets_email_index ON public.password_resets USING btree (email);


--
-- Name: personal_access_tokens_tokenable_type_tokenable_id_index; Type: INDEX; Schema: public; Owner: postgres
--

CREATE INDEX personal_access_tokens_tokenable_type_tokenable_id_index ON public.personal_access_tokens USING btree (tokenable_type, tokenable_id);


--
-- PostgreSQL database dump complete
--

--
-- Database "societe" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: societe; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE societe WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE societe OWNER TO postgres;

\connect societe

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: fournisseur; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.fournisseur (
    numf integer NOT NULL,
    nomf character varying(30),
    villef character varying(30),
    statut character varying(30)
);


ALTER TABLE public.fournisseur OWNER TO postgres;

--
-- Name: livraison; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.livraison (
    numu integer,
    nump integer,
    numf integer,
    quantite integer
);


ALTER TABLE public.livraison OWNER TO postgres;

--
-- Name: produit; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produit (
    nump integer NOT NULL,
    nomp character varying(30),
    couleur character varying(30),
    poids integer
);


ALTER TABLE public.produit OWNER TO postgres;

--
-- Name: usine; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.usine (
    numu integer NOT NULL,
    nomu character varying(30),
    villeu character varying(30)
);


ALTER TABLE public.usine OWNER TO postgres;

--
-- Data for Name: fournisseur; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.fournisseur (numf, nomf, villef, statut) FROM stdin;
1	fournisseur1	Toamasina	\N
\.


--
-- Data for Name: livraison; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.livraison (numu, nump, numf, quantite) FROM stdin;
1	1	1	50
2	1	1	400
\.


--
-- Data for Name: produit; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.produit (nump, nomp, couleur, poids) FROM stdin;
1	Produit1	bleu	100
\.


--
-- Data for Name: usine; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.usine (numu, nomu, villeu) FROM stdin;
1	usine1	Toamasina
2	usine2	Antananarivo
\.


--
-- Name: fournisseur fourinisseur_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.fournisseur
    ADD CONSTRAINT fourinisseur_pkey PRIMARY KEY (numf);


--
-- Name: produit produit_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produit
    ADD CONSTRAINT produit_pkey PRIMARY KEY (nump);


--
-- Name: usine usine_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.usine
    ADD CONSTRAINT usine_pkey PRIMARY KEY (numu);


--
-- Name: livraison livraison_numf_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_numf_fkey FOREIGN KEY (numf) REFERENCES public.fournisseur(numf);


--
-- Name: livraison livraison_nump_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_nump_fkey FOREIGN KEY (nump) REFERENCES public.produit(nump);


--
-- Name: livraison livraison_numu_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.livraison
    ADD CONSTRAINT livraison_numu_fkey FOREIGN KEY (numu) REFERENCES public.usine(numu);


--
-- PostgreSQL database dump complete
--

--
-- Database "test" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: test; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE test WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE test OWNER TO postgres;

\connect test

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- PostgreSQL database dump complete
--

--
-- Database "user1" dump
--

--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)
-- Dumped by pg_dump version 12.22 (Ubuntu 12.22-0ubuntu0.20.04.4)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: user1; Type: DATABASE; Schema: -; Owner: user1
--

CREATE DATABASE user1 WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'fr_FR.UTF-8' LC_CTYPE = 'fr_FR.UTF-8';


ALTER DATABASE user1 OWNER TO user1;

\connect user1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: test; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.test (
    id integer NOT NULL,
    nom text,
    datenaisse date
);


ALTER TABLE public.test OWNER TO postgres;

--
-- Data for Name: test; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.test (id, nom, datenaisse) FROM stdin;
\.


--
-- Name: test test_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.test
    ADD CONSTRAINT test_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

--
-- PostgreSQL database cluster dump complete
--

