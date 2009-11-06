'<ul> \n\
  ' + Mojo.enumerate(o, Mojo.normalize(o.users), function(o){
    return '\n\
    <li>' + (Mojo.escape(Mojo.normalize(o.name))) + ' is ' + (Mojo.escape(Mojo.normalize(o.age))) + '</li>\n\
  '}) + '\n\
</ul>'