# Sample Data

These files provide a tiny AppStream feed, desktop entry, and related assets
for development builds of the Ubuntu Unity Software Center. They let you run
`unity-software` directly from the build tree without installing distribution
metadata.

To populate the build directory with this sample content, run:

```
meson compile -C build install-sample-data
```

The command copies the files from this folder into `build/data`, matching the
layout used by system AppStream providers. You can replace these samples with
real distribution data at any time.
