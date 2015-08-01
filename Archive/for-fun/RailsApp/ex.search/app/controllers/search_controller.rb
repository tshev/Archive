class SearchController < ApplicationController
  def index
  end

  def find
		limit = params['limit'] || 0
		phrase = params['query']
		@search_results = load_params(phrase, limit)
  end
end
