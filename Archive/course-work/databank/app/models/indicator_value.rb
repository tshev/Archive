class IndicatorValue < ActiveRecord::Base
  belongs_to :country
  belongs_to :indicator
	def self.select_multiple(cid, iid, year, limit)
		self.limit(limit).where(country_id: cid).where(indicator_id: iid)
	end
end
