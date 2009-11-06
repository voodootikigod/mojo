'<ul> \n\
  ' + Mojo.enumerate(o, o.users, function(o){
    return '\n\
    <li>' + (o.name) + ' is ' + (o.age) + '</li>\n\
  '}) + '\n\
</ul>'