'<h2>' + (o.name) + '</h2>\n\
' + Mojo.enumerate(o, o.biography, function(o){
    return '\n\
  <h3>Bio</h3>\n\
  <p>' + (o.biography) + '</p>\n\
'}) + ''