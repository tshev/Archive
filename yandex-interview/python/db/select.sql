select users.uid, users.name, count(messages.uid) from users 
left join messages on users.uid=messages.uid group by users.uid;

