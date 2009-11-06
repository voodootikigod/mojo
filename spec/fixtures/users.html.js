'<ul> \n\
  ' + Mojo.enumerate(o, Mojo.prop(o.users), function(o){
    return '\n\
    <li>' + (Mojo.escape(Mojo.prop(o.name))) + ' is ' + (Mojo.escape(Mojo.prop(o.age))) + '</li>\n\
  '}) + '\n\
</ul>'