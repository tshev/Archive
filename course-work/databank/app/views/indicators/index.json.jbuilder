json.array!(@indicators) do |indicator|
  json.extract! indicator, :id, :name, :code
  json.url indicator_url(indicator, format: :json)
end
