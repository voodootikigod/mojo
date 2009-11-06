
describe 'Mojo'
  describe '.version'
    it 'should be a triple'
      Mojo.version.should.match(/^\d+\.\d+\.\d+$/)
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
		
		  it 'should not render the section when undefined'
		    var s = render('profile', { name: 'Tj' })
			  s.should.include('<h2>Tj</h2>')
			  s.should.not.include('<h3>Bio</h3>')
			  s.should.not.include('<p>Some foo bar</p>')
		  end
		end
  end
end