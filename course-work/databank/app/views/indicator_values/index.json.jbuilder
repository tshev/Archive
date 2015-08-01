json.array!(@indicator_values) do |indicator_value|
  json.extract! indicator_value, :id, :country_id, :indicator_id, :value, :measure_datetime
  json.url indicator_value_url(indicator_value, format: :json)
end
