class ApplicationController < ActionController::Base
  # Prevent CSRF attacks by raising an exception.
  # For APIs, you may want to use :null_session instead.
  protect_from_forgery with: :exception
	def load_params(phrase, limit)
		require "net/http"
		require "nokogiri"
		require "rest-client"
		resource = "site:http://ex.ua/"
		query = "https://www.google.com.ua/search?q=#{resource}+#{phrase.split(' ').join('+')}"
		query = URI.encode(query)
		res = RestClient.get(query)
		html_doc = Nokogiri::HTML(res)
		results = []
	 	html_doc.css("cite").each do |p|
			txt = RestClient.get(p.text)
			txt= Nokogiri::HTML(txt)
			name = txt.css("h1" ) do |i|
				i
			end
			ps = []
		 	qs = txt.css("p") do |i|
				puts i
				ps.add(i.text)
				i
			end
			results.push("<h3><a target='blank' href='http://#{p.text}'>#{name.text}</a></h3>" + "<p style='color:#111;'>#{qs[1..2]}</p>" )
		end
		results
	end
end
