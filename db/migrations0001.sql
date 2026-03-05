/* Footlight Table Migrations */

pragma foreign_keys = on;

create table settings (
    key varchar,
    value integer not null,
    primary key (key)
);

insert into settings (
    key, value
) values (
    'db_ver', 1
);

create table fixture_type (
    id integer,
    model varchar,
    manufacturer varchar,
    primary key (id)
);

create table fixture (
    id integer,
    name varchar not null, 
    fixture_type_id integer not null,
    foreign key (fixture_type_id) references fixture_type(id),
    primary key (id)
);

create table state (
    id integer, 
    name varchar not null, 
    primary key (id)
);

create table state_fixture (
    id integer, 
    state_id integer not null, 
    fixture_id integer not null, 
    foreign key (state_id) references state(id),
    foreign key (fixture_id) references fixture(id),
    primary key (id)
);

create table cue (
    id integer,
    sequence varchar,
    prompt varchar,
    state_id integer not null,
    foreign key (state_id) references state(id),
    primary key (id)
)
