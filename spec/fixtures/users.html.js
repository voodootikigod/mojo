'<ul> \n\
  ' + Mojo.enumerate(o, o.users, function(o){
    return '\n\
    <li>' + (Mojo.escape(o.name)) + ' is ' + (Mojo.escape(o.age)) + '</li>\n\
  '}) + '\n\
</ul>'