'<ul> \n\
  ' + Mojo.enumerate(o.users, function(o){
    return '\n\
    <li>' + (o.name) + ' is ' + (o.age) + '</li>\n\
  '}) + '\n\
</ul>'