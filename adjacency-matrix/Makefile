SRCS := $(wildcard *.c)
OBJDIR = .build
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

DEPDIR = .dep
DEPS := $(SRCS:%.c=$(DEPDIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

.PHONY: clean
TARGET = out

$(OBJDIR)/%.o: %.c | $(OBJDIR) $(DEPDIR)
	@echo [CC] $@
	@$(CC) -c $(CFLAGS) $(DEPFLAGS) -o $@ $<

$(TARGET): $(OBJS)
	@echo [LD] $@
	@$(CC) $(LDFLAGS) -o $@ $^

vis: $(TARGET)
	./$(TARGET) | dot -Tpdf > vis.pdf

clean:
	@rm -rf $(OBJDIR) $(DEPDIR) $(TARGET)

$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

$(DEPFILES):

include $(wildcard $(DEPFILES))
