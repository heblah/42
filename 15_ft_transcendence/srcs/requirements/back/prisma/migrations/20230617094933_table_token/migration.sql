-- CreateTable
CREATE TABLE "Token2FA" (
    "id" INTEGER NOT NULL,
    "value" TEXT NOT NULL
);

-- CreateIndex
CREATE UNIQUE INDEX "Token2FA_id_key" ON "Token2FA"("id");
