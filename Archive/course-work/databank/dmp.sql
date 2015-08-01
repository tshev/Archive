--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: countries; Type: TABLE; Schema: public; Owner: taras; Tablespace: 
--

CREATE TABLE countries (
    id integer NOT NULL,
    name character varying(255),
    code character varying(255),
    created_at timestamp without time zone,
    updated_at timestamp without time zone
);


ALTER TABLE public.countries OWNER TO taras;

--
-- Name: countries_id_seq; Type: SEQUENCE; Schema: public; Owner: taras
--

CREATE SEQUENCE countries_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.countries_id_seq OWNER TO taras;

--
-- Name: countries_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: taras
--

ALTER SEQUENCE countries_id_seq OWNED BY countries.id;


--
-- Name: indicator_values; Type: TABLE; Schema: public; Owner: taras; Tablespace: 
--

CREATE TABLE indicator_values (
    id integer NOT NULL,
    country_id integer,
    indicator_id integer,
    value double precision,
    created_at timestamp without time zone,
    updated_at timestamp without time zone
);


ALTER TABLE public.indicator_values OWNER TO taras;

--
-- Name: indicator_values_id_seq; Type: SEQUENCE; Schema: public; Owner: taras
--

CREATE SEQUENCE indicator_values_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.indicator_values_id_seq OWNER TO taras;

--
-- Name: indicator_values_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: taras
--

ALTER SEQUENCE indicator_values_id_seq OWNED BY indicator_values.id;


--
-- Name: indicators; Type: TABLE; Schema: public; Owner: taras; Tablespace: 
--

CREATE TABLE indicators (
    id integer NOT NULL,
    name character varying(255),
    code character varying(255),
    created_at timestamp without time zone,
    updated_at timestamp without time zone
);


ALTER TABLE public.indicators OWNER TO taras;

--
-- Name: indicators_id_seq; Type: SEQUENCE; Schema: public; Owner: taras
--

CREATE SEQUENCE indicators_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.indicators_id_seq OWNER TO taras;

--
-- Name: indicators_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: taras
--

ALTER SEQUENCE indicators_id_seq OWNED BY indicators.id;


--
-- Name: schema_migrations; Type: TABLE; Schema: public; Owner: taras; Tablespace: 
--

CREATE TABLE schema_migrations (
    version character varying(255) NOT NULL
);


ALTER TABLE public.schema_migrations OWNER TO taras;

--
-- Name: id; Type: DEFAULT; Schema: public; Owner: taras
--

ALTER TABLE ONLY countries ALTER COLUMN id SET DEFAULT nextval('countries_id_seq'::regclass);


--
-- Name: id; Type: DEFAULT; Schema: public; Owner: taras
--

ALTER TABLE ONLY indicator_values ALTER COLUMN id SET DEFAULT nextval('indicator_values_id_seq'::regclass);


--
-- Name: id; Type: DEFAULT; Schema: public; Owner: taras
--

ALTER TABLE ONLY indicators ALTER COLUMN id SET DEFAULT nextval('indicators_id_seq'::regclass);


--
-- Data for Name: countries; Type: TABLE DATA; Schema: public; Owner: taras
--

COPY countries (id, name, code, created_at, updated_at) FROM stdin;
\.


--
-- Name: countries_id_seq; Type: SEQUENCE SET; Schema: public; Owner: taras
--

SELECT pg_catalog.setval('countries_id_seq', 1, false);


--
-- Data for Name: indicator_values; Type: TABLE DATA; Schema: public; Owner: taras
--

COPY indicator_values (id, country_id, indicator_id, value, created_at, updated_at) FROM stdin;
\.


--
-- Name: indicator_values_id_seq; Type: SEQUENCE SET; Schema: public; Owner: taras
--

SELECT pg_catalog.setval('indicator_values_id_seq', 1, false);


--
-- Data for Name: indicators; Type: TABLE DATA; Schema: public; Owner: taras
--

COPY indicators (id, name, code, created_at, updated_at) FROM stdin;
\.


--
-- Name: indicators_id_seq; Type: SEQUENCE SET; Schema: public; Owner: taras
--

SELECT pg_catalog.setval('indicators_id_seq', 1, true);


--
-- Data for Name: schema_migrations; Type: TABLE DATA; Schema: public; Owner: taras
--

COPY schema_migrations (version) FROM stdin;
20141223162320
20141223162429
20141223163140
\.


--
-- Name: countries_pkey; Type: CONSTRAINT; Schema: public; Owner: taras; Tablespace: 
--

ALTER TABLE ONLY countries
    ADD CONSTRAINT countries_pkey PRIMARY KEY (id);


--
-- Name: indicator_values_pkey; Type: CONSTRAINT; Schema: public; Owner: taras; Tablespace: 
--

ALTER TABLE ONLY indicator_values
    ADD CONSTRAINT indicator_values_pkey PRIMARY KEY (id);


--
-- Name: indicators_pkey; Type: CONSTRAINT; Schema: public; Owner: taras; Tablespace: 
--

ALTER TABLE ONLY indicators
    ADD CONSTRAINT indicators_pkey PRIMARY KEY (id);


--
-- Name: index_indicator_values_on_country_id; Type: INDEX; Schema: public; Owner: taras; Tablespace: 
--

CREATE INDEX index_indicator_values_on_country_id ON indicator_values USING btree (country_id);


--
-- Name: index_indicator_values_on_indicator_id; Type: INDEX; Schema: public; Owner: taras; Tablespace: 
--

CREATE INDEX index_indicator_values_on_indicator_id ON indicator_values USING btree (indicator_id);


--
-- Name: unique_schema_migrations; Type: INDEX; Schema: public; Owner: taras; Tablespace: 
--

CREATE UNIQUE INDEX unique_schema_migrations ON schema_migrations USING btree (version);


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

