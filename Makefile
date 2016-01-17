.PHONY: test clean
test:
	@$(foreach src,$(shell find -name '*.s'),./test $(src);)
clean:
	@find -name a.out | xargs rm -f
