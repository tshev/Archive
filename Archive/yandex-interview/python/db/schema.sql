create table users (
  uid int not null auto_increment primary key,
  name char(255)
);


create table messages (
  mid int not null auto_increment primary key,
  uid int,  
  msg char(255),
  foreign key(uid) references users(uid)
);

