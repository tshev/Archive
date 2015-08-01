#include <memory>
#include <iostream>

class object_t {
public:
	template<typename T>
	object_t(T x): self_ { std::make_shared<model_t<T>>(std::move(x)) } { }

	void draw(std::ostream &out, size_t position) const {
		self_->draw(out, position);
	}
private:
	struct concept_t {
		virtual ~concept_t() = default;
		virtual void draw(std::ostream&, size_t) const = 0;
	};

	template<typename T>
	struct model_t : concept_t{
		model_t(T x) : data_(std::move(x)) { }
		void draw(std::ostream& out, size_t position) const {
			data_.draw(out, position);
		}
		T data_;
	};

	std::shared_ptr<const concept_t> self_;
};

