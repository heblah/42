/*
  Warnings:

  - A unique constraint covering the columns `[ChannelName]` on the table `Channel` will be added. If there are existing duplicate values, this will fail.

*/
-- CreateIndex
CREATE UNIQUE INDEX "Channel_ChannelName_key" ON "Channel"("ChannelName");
