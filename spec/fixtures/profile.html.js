'<h2>' + (Mojo.escape(Mojo.prop(o.name))) + '</h2>\n\
' + Mojo.enumerate(o, Mojo.prop(o.biography), function(o){
    return '\n\
  <h3>Bio</h3>\n\
  <p>' + (Mojo.escape(Mojo.prop(o.biography))) + '</p>\n\
'}) + ''