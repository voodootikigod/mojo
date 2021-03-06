
describe 'Mojo'
  describe '.version'
    it 'should be a triple'
      Mojo.version.should.match(/^\d+\.\d+\.\d+$/)
    end
  end

  describe '{ . }'
    it 'should reference self '
      var s = render('welcome', 'Tj')
      s.should.include('<p>Welcome Tj</p>')
    end
  end

  describe '{ name }'
    it 'should buffer the given property name'
      var s = render('article', { title: 'Mojo', body: 'Is awesome' })
      s.should.include('<div class="article">')
      s.should.include('<h2>Mojo</h2>')
      s.should.include('<p>Is awesome</p>')
      s.should.include('</div>')
    end
  
    it 'should escape property values'
      var s = render('article', { title: 'Foo & Bar' })
      s.should.include('<h2>Foo &amp; Bar</h2>')
    end

    it 'should invoke the property if its a function'
      var s = render('article', { title: function(){ return 'Foo' } })
      s.should.include('<h2>Foo</h2>')
    end
  end

  describe '{! comment }'
    it 'should render nothing'
      var s = render('comments')
      strip(s).should.be_empty
    end
  end

  describe '{# name } {/ name }'
    describe 'with enumerable property'
      it 'should render the collection'
        var tj = { name: 'Tj', age: 22 }
        var joe = { name: 'Joe', age: 18 }
        var s = render('users', { users: [tj, joe] })
        s.should.include('<ul>')
        s.should.include('<li>Tj is 22</li>')
        s.should.include('<li>Joe is 18</li>')
        s.should.include('</ul>')
      end
    
      it 'should render the collection when referencing self'
        var s = render('messages', ['Hey', 'There'])
        s.should.include('<li>Hey</li>')
        s.should.include('<li>There</li>')
      end
    end

    describe 'with non-enumerable property'
      it 'should render the section when available'
        var s = render('profile', { name: 'Tj', biography: 'Some foo bar' })
        s.should.include('<h2>Tj</h2>')
        s.should.include('<h3>Bio</h3>')
        s.should.include('<p>Some foo bar</p>')
      end
    
      it 'should not render the section when falsey'
        var s = render('profile', { name: 'Tj', biography: false })
        s.should.include('<h2>Tj</h2>')
        s.should.not.include('<h3>Bio</h3>')
        s.should.not.include('<p>Some foo bar</p>')
      end
    
      it 'should render the section when a functions return val is truthy'
        var s = render('profile', { name: 'Tj', biography: function(){ return true } })
        s.should.include('<h3>Bio</h3>')
      end
    
      it 'should not render the section when a functions return val is falsey'
        var s = render('profile', { name: 'Tj', biography: function(){ return false } })
        s.should.not.include('<h3>Bio</h3>')
      end
    
      it 'should not render the section when undefined'
        var s = render('profile', { name: 'Tj' })
        s.should.include('<h2>Tj</h2>')
        s.should.not.include('<h3>Bio</h3>')
        s.should.not.include('<p>Some foo bar</p>')
      end
    end
  end

  describe 'large templates'
    it 'should render properly'
      var s = render('page', {
        title: 'Articles',
        articles: [
          { title: 'One', body: 'some more one' },
          { title: 'Two', body: 'some more two', published: true }
        ]
      })
      s.should.include('<title>Articles</title>')
      s.should.include('<h1>Articles</h1>')
      s.should.include('<h2>One</h2>')
      s.should.include('<p>some more one</p>')
      s.should.include('<h2>Two</h2>')
      s.should.include('<p>some more two</p>')
      s.should.include('<p>Two is published</p>')
    end
  end
end